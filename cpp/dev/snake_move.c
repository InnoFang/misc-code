#include <stdio.h>
#include <conio.h>
#include <windows.h>
//̰���߱����Ŀ�Ⱥ͸߶�
#define HEIGHT (30)
#define WIDTH HEIGHT
//����������λ��
int xCenter = HEIGHT%2==0 ? HEIGHT/2 : HEIGHT/2+1;
int yCenter = WIDTH%2==0 ? WIDTH/2 : WIDTH/2+1;
//̰���ߵĳ���
int snakesLen = 10;
//̰���ߵ���󳤶�
int snakesMaxLen = (HEIGHT-2) * (WIDTH-2);
//һ����̰�����ƶ��Ľṹ������
struct{
    int x;
    int y;
}snakes[(HEIGHT-2) * (WIDTH-2)];
//��ͷ����β��snakes�����е��±꣨������
int headerIndex, tailIndex;
HANDLE hConsole;  //����̨���
// ���ù��λ�ã�xΪ�У�yΪ��
void setPosition(int x, int y){
    COORD coord;
    coord.X = 2*y;
    coord.Y = x;
    SetConsoleCursorPosition(hConsole, coord);
}
// ������ɫ
void setColor(int color){
    SetConsoleTextAttribute(hConsole, color);
}
//��ʼ��
void init(){
    int xCenter = HEIGHT%2==0 ? HEIGHT/2 : HEIGHT/2+1;
    int yCenter = WIDTH%2==0 ? WIDTH/2 : WIDTH/2+1;
    int x, y, i;
    int offset;
    CONSOLE_CURSOR_INFO cci;
   
    headerIndex = 0;
    tailIndex = snakesLen-1;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ع��
    GetConsoleCursorInfo(hConsole, &cci);
    cci.bVisible = 0;
    SetConsoleCursorInfo(hConsole, &cci);
   
    //���ô��ڴ�С
    system("mode con: cols=64 lines=32");
    //��ӡ�������������
    for(x=0; x<WIDTH; x++){
        for(y=0; y<HEIGHT; y++){
            if(y==0 || y==WIDTH-1 || x==0 || x==HEIGHT-1){  //����߿�
                setColor(4);
                printf("��");
            }else{  //̰���߻����
                setColor(2);
                printf("��");
            }
        }
        printf("\n");
    }
    //���̰���߲���ʼ��snake����
    offset = snakesLen%2==0 ? snakesLen/2 : snakesLen/2-1;
    setPosition(xCenter, yCenter-offset);
    setColor(0xe);
   
    for(i=0; i<snakesLen; i++){
        printf("%s", "��");
        snakes[i].x = xCenter;
        snakes[i].y = yCenter-offset+i;
    }
}
// ���ƶ�
void move(char direction){
    int headerX = snakes[headerIndex].x;
    int headerY = snakes[headerIndex].y;
    switch(direction){
        case 'w':
            headerX--;
            break;
        case 's':
            headerX++;
            break;
        case 'a':
            headerY--;
            break;
        case 'd':
            headerY++;
            break;
    }
    //�������ͷ
    setPosition(headerX, headerY);
    setColor(0xe);
    printf("%s", "��");
    //ɾ����β
    setPosition(snakes[tailIndex].x, snakes[tailIndex].y);
    setColor(2);
    printf("%s", "��");
   
    //����headerIndex��tailIndex
    headerIndex = headerIndex==0 ? snakesMaxLen-1 : headerIndex-1;
    snakes[headerIndex].x = headerX;
    snakes[headerIndex].y = headerY;
    tailIndex = tailIndex==0 ? snakesMaxLen-1 : tailIndex-1;
}
//�´��ƶ��ķ���
char nextDirection(char ch, char directionOld){
    int sum = ch+directionOld;
    ch = tolower(ch);
    if( (ch=='w' || ch=='a' || ch=='s' || ch=='d') && sum!=197 && sum!=234 ){
        return ch;
    }else{
        return directionOld;
    }
}
int main(){
    char charInput, direction = 'a';
    init();
   
    charInput = tolower(getch());
    direction = nextDirection(charInput, direction);
    //��ͣ���ƶ�̰����
    while(1){
        if(kbhit()){
            charInput = tolower(getch());
            direction = nextDirection(charInput, direction);
        }
        move(direction);
        Sleep(500);
    }
    return 0;
}
