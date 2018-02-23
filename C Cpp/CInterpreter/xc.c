#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int token;           // current token
char *src, *old_src; // pointer to source code string
int poolsize;        // default size of text/data/stack
int line;            // line number

/* �����ָ��/�ڴ��ַ�����ݣ����Ǿ����޷��ŵ� */
int *code,     // code segment
    *old_code, // for dump code segment
    *stack;    // stack

/* ����ַ��� */
char* data;    // data segment

/* virtual machine registers */
int *pc, // ���������������ŵ���һ���ڴ��ַ���õ�ַ�д���� ��һ�� Ҫִ�еļ����ָ��
    *sp, // ָ��Ĵ�������Զָ��ǰ��ջ����ע���������ջ��λ�ڸߵ�ַ����͵�ַ�����ģ�������ջʱ SP ��ֵ��С
    *bp, // ��ַָ�롣Ҳ������ָ��ջ��ĳЩλ�ã��ڵ��ú���ʱ��ʹ�õ���
    ax,  // ͨ�üĴ��������ǵ�������У������ڴ��һ��ָ��ִ�к�Ľ��
    cycle;

// instructions
enum { LEA ,IMM ,JMP ,CALL,JZ  ,JNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PUSH,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,CLOS,PRTF,MALC,MSET,MCMP,EXIT
     };


// tokens and classes (operators last and in precedence order)
enum {
    Num = 128, Fun, Sys, Glo, Loc, Id,
    Char, Else, Enum, If, Int, Return, Sizeof, While,
    Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

struct identifier {
	int token;	// �ñ�ʶ�����صı��
	int hash;	// ��ʶ���Ĺ�ϣֵ
	char * name;// ��ű�ʶ��������ַ���
	int class;	// �ñ�ʶ������������֣�ȫ�ֱ�����ֲ�������
	int type;	// ��ʶ�������ͣ���������Ǹ������������� int �͡�char �ͻ���ָ����
	int value;	// ��������ʶ����ֵ�����ʶ���Ǻ������մ�ź����ĵ�ַ

	int Bclass;	///  C �����б�ʶ��������ȫ�ֵ�Ҳ�����Ǿֲ��ģ�
	int Btype;  /// ���ֲ���ʶ����������ȫ�ֱ�ʶ����ͬʱ��
	int Bvalue;	/// ��������ȫ�ֱ�ʶ������Ϣ
};


int *current_id, // current parsed ID
    *symbols,    // symbol table
    line,        // line number of source code
    token_val;   // value of current token (mainly for number)

// fields of identifier
enum {Token, Hash, Name, Type, Class, Value, BType, BClass, BValue, IdSize};

// types of variable/function
enum { CHAR, INT, PTR };
int *idmain; // the `main` function

/* ���ڴʷ���������ȡ��һ����ǣ������Զ����Կհ��ַ� */
void next() {
	char *last_pos;
	token = *src++;
	int hash;

	while (token = *src) {
		++ src;
		// parse token here
		/* the end of the line */
		if (token == '\n') {
			++line;
		}
		/* macro */
		else if (token == '#') {
			// skip macro, beacuse we will not support it
			while (*src != 0 && *src != '\n') {
				src++;
			}
		}
		/* variable */
		else if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') || (token == '_')) {
			// parse identifier
			last_pos = src - 1;
			hash = token;

			while ((*src >= 'a' & *src <= 'z') || (*src >= 'A' && *src <= 'Z') || (*src >= '0' && *src <= '9') || (*src == '_')) {
				hash = hash * 147 + *src;
				src++;
			}

			// look for existing identifier, linear search
			current_id = symbols;
			while (current_id[Token]) {
				if (current_id[Hash] = hash && !memcmp((char*)current_id[Name], last_pos, src - last_pos)) {
					// found one, return
					token = current_id[Token];
					return;
				}
				current_id = current_id + IdSize;
			}

			// store new ID
			current_id[Name] = (int) last_pos;
			current_id[Hash] = hash;
			token = current_id[Token] = Id;
			return;
		}
		/* number */
		else if (token >= '0' && token <= '9') {
			// parse number, three kinds: dec(123) hex(0x123) oct(017)
			token_val = token - '0';
			if (token_val > 0) {
				// dec, starts with [1-9]
				while (*src >= '0' && *src <= '9') {
					token_val = token_val * 10 + (*src++ - '0');
				}
			} else {
				// starts with number 0
				if (*src == 'x' || *src == 'X') {
					// hex
					token = *++src;
					while ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
						token_val = token_val * 16 + (token & 15) + (token >= 'A' ? 9 : 0);
						token = *++src;
					}
				} else {
					// oct
					while (*src >= '0' && *src <= '7') {
						token_val = token_val * 8 + (*src++ - '0');
					}
				}
			}

			token = Num;
			return;
		}
		/* string */
		else if (token == '"' || token == '\'') {
			// parse string literal, currently, the only suported escape
			// character is '\n', store the string literal into data.
			last_pos = data;
			while (*src != 0 && *src != token) {
				token_val = *src++;
				if (token_val == '\\') {
					// escape character
					token_val = *src++;
					if (token_val == 'n') {
						token_val = '\n';
					}
				}

				if (token == '"') {
					*data++ = token_val;
				}
			}

			src++;
			// if it is a single character, return Num token
			if (token == '"') {
				token_val = (int) last_pos;
			} else {
				token = Num;
			}
			return;
		}
		/* comment */
		else if (token == '/') {
			if (*src == '/') {
				// skip comment
				while (*src != 0 && *src != '\n') {
					++src;
				}
			} else {
				// divide operator
				token = Div;
				return;
			}
		}
		/* other */
		else if (token == '=') {
			// parse '==' and '='
			if (*src == '=') {
				src ++;
				token = Eq;
			} else {
				token = Assign;
			}
			return;
		} else if (token == '+') {
			// parse '+' and '++'
			if (*src == '+') {
				src ++;
				token = Inc;
			} else {
				token = Add;
			}
			return;
		} else if (token == '-') {
			// parse '-' and '--'
			if (*src == '-') {
				src ++;
				token = Dec;
			} else {
				token = Sub;
			}
			return;
		} else if (token == '!') {
			// parse '!='
			if (*src == '=') {
				src++;
				token = Ne;
			}
			return;
		} else if (token == '<') {
			// parse '<=', '<<' or '<'
			if (*src == '=') {
				src ++;
				token = Le;
			} else if (*src == '<') {
				src ++;
				token = Shl;
			} else {
				token = Lt;
			}
			return;
		} else if (token == '>') {
			// parse '>=', '>>' or '>'
			if (*src == '=') {
				src ++;
				token = Ge;
			} else if (*src == '>') {
				src ++;
				token = Shr;
			} else {
				token = Gt;
			}
			return;
		} else if (token == '|') {
			// parse '|' or '||'
			if (*src == '|') {
				src ++;
				token = Lor;
			} else {
				token = Or;
			}
			return;
		} else if (token == '&') {
			// parse '&' and '&&'
			if (*src == '&') {
				src ++;
				token = Lan;
			} else {
				token = And;
			}
			return;
		} else if (token == '^') {
			token = Xor;
			return;
		} else if (token == '%') {
			token = Mod;
			return;
		} else if (token == '*') {
			token = Mul;
			return;
		} else if (token == '[') {
			token = Brak;
			return;
		} else if (token == '?') {
			token = Cond;
			return;
		} else if (token == '~' || token == ';' || token == '{' || token == '}' || token == '(' || token == ')' || token == ']' || token == ',' || token == ':') {
			// directly return the character as token;
			return;
		}
	}
	return;
}

/* ���ڽ���һ�����ʽ */
void expression(int level) {
	// nothing to do, but soon
}

/* �﷨��������ڣ��������� C ���Գ��� */
void program() {
	next(); // get next token
	while (token > 0) {
		printf("token is: %c\n", token);
		next();
	}
}

/* ���������ڣ����ڽ���Ŀ����� */
int eval() {
	int op, *tmp;

	while (1) {
		if (op == IMM)     {
			ax = *pc++;    // load immediate value to ax
		} else if (op == LC) {
			ax = *(char*) ax;    // load character to ax, address in ax
		} else if (op == LI) {
			ax = *(int*) ax;    // load integer to ax, address in ax
		} else if (op == SC) {
			ax = *(char*) *sp++ = ax;    // save character to address, value in ax, address on stack
		} else if (op == SC) {
			*(int*)*sp++ = ax;    // save integer to address, value in ax, address on stack
		} else if (op == PUSH) {
			*--sp = ax;    // push the value of ax onto the stack
		} else if (op == JMP) {
			pc = (int*)*pc;    // jump to the address
		} else if (op == JZ) {
			pc = ax ? pc + 1 : (int*)*pc;    // jump if ax is zero
		} else if (op == JNZ) {
			pc = ax ? (int*)*pc : pc + 1;    // jump if ax is zero
		} else if (op == CALL) {
			*--sp = (int)(pc + 1);    // call subroutine
			pc = (int*)*pc;
		}
		// else if (op == RET) { pc = (int*)*sp++; }						// return from subroutine�� ֮�����ǽ��� LEV ָ��������
		else if (op == ENT) {
			*--sp = (int)bp;    // make new stack frame, �����浱ǰ��ջָ�룬ͬʱ��ջ�ϱ���һ���Ŀռ䣬���Դ�žֲ�����
			bp = sp;
			sp = sp - *pc++;
		} else if (op == ADJ) {
			sp = sp + *pc++;    // add esp, <size>  ; remove arguments from frame, �������Ӻ���ʱѹ��ջ�е��������
		} else if (op == LEV) {
			sp = bp;    // restore call frame and PC
			bp = (int*)*sp++;
			pc = (int*)*sp++;
		} else if (op == LEA) {
			ax = (int)(bp + *pc++);    // load address for arguments
		}

		/* �����ָ��, Ϊ C ������֧�ֵ���������ṩ��Ӧ���ָ�ÿ����������Ƕ�Ԫ�ģ�����������������һ����������ջ�����ڶ����������� ax ��*/
		else if (op == OR)  ax = *sp++ | ax;
		else if (op == XOR) ax = *sp++ ^ ax;
		else if (op == AND) ax = *sp++ & ax;
		else if (op == EQ)  ax = *sp++ == ax;
		else if (op == NE)  ax = *sp++ != ax;
		else if (op == LT)  ax = *sp++ < ax;
		else if (op == LE)  ax = *sp++ <= ax;
		else if (op == GT)  ax = *sp++ >  ax;
		else if (op == GE)  ax = *sp++ >= ax;
		else if (op == SHL) ax = *sp++ << ax;
		else if (op == SHR) ax = *sp++ >> ax;
		else if (op == ADD) ax = *sp++ + ax;
		else if (op == SUB) ax = *sp++ - ax;
		else if (op == MUL) ax = *sp++ * ax;
		else if (op == DIV) ax = *sp++ / ax;
		else if (op == MOD) ax = *sp++ % ax;

		/* ���ú���, ��������������Ҫ�õ��ĺ����У�exit, open, close, read, printf, malloc, memset */
		else if (op == EXIT) {
			printf("exit(%d)", *sp);
			return *sp;
		} else if (op == OPEN) {
			ax = open((char *)sp[1], sp[0]);
		} else if (op == CLOS) {
			ax = close(*sp);
		} else if (op == READ) {
			ax = read(sp[2], (char *)sp[1], *sp);
		} else if (op == PRTF) {
			tmp = sp + pc[1];
			ax = printf((char *)tmp[-1], tmp[-2], tmp[-3], tmp[-4], tmp[-5], tmp[-6]);
		} else if (op == MALC) {
			ax = (int)malloc(*sp);
		} else if (op == MSET) {
			ax = (int)memset((char *)sp[2], sp[1], *sp);
		} else if (op == MCMP) {
			ax = memcmp((char *)sp[2], (char *)sp[1], *sp);
		}
		/* unknown instruction */
		else {
			printf("unknown instruction:%d\n", op);
			return -1;
		}
	}

	return 0;
}

int main(int argc, char***argv) {
	int i, fd;

	argc--;
	argv++;

	poolsize = 256 * 1024; // arbitrary size
	line = 1;

	if ( (fd = open(*argv, 0)) < 0 ) {
		printf("could not open(%s)\n", *argv);
		return -1;
	}

	if ( !(src = old_src = malloc(poolsize)) ) {
		printf("could not malloc(%d) for source area\n", poolsize);
		return -1;
	}

	// read the source life
	if ( (i = read(fd, src, poolsize - 1)) <= 0 ) {
		printf("read() returned %d\n", i);
		return -1;
	}

	src[i] = 0; // add EOF character
	close(fd);

	// allocate memory for virtual machine
	if ( !(code = old_code = malloc(poolsize)) ) {
		printf("could not malloc(%d) for code area\n", poolsize);
		return -1;
	}

	if ( !(data = malloc(poolsize)) ) {
		printf("could not malloc(%d) for data area\n", poolsize);
		return -1;
	}

	if ( !(stack = malloc(poolsize)) ) {
		printf("could not malloc(%d) for stack area\n", poolsize);
		return -1;
	}

	memset(code, 0, poolsize);
	memset(data, 0, poolsize);
	memset(stack, 0 , poolsize);

	bp = sp = (int*)((int)stack + poolsize);
	ax = 0;

	src = "char else enum if int return sizeof while open read close printf malloc memset memcmp exit void main";

	// add keywords to symbol table
	i = Char;
	while (i <= While) {
		next();
		current_id[Token] = i++;
	}

	// add library to symbol table
	i = OPEN;
	while (i <= EXIT) {
		next();
		current_id[Class] = Sys;
		current_id[Type] = INT;
		current_id[Value] = i++;
	}

	next();
	current_id[Token] = Char; 	// handle void type
	next();
	idmain = current_id;		// keep track of main

	///test code///
//	i = 0;
//	code[i++] = IMM;
//	code[i++] = 10;
//	code[i++] = PUSH;
//	code[i++] = IMM;
//	code[i++] = 20;
//	code[i++] = ADD;
//	code[i++] = PUSH;
//	code[i++] = EXIT;
//	pc = code;
	///test code///


	program();
	return eval();
}
