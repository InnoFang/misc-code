#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MaxSize 100
/*�������������Ͷ���*/
typedef char DataType;
typedef enum{
	Link, Thread
} PointerTag;

typedef struct Node/*�������*/
{
	DataType data;
	struct Node *lchild, *rchild;
	PointerTag ltag, rtag;
} BiThrNode;

typedef BiThrNode* BiThrTree;

/*��������*/
void CreateBitTree2(BitThrTree *T, char str[]);
int main()
{
	return 0;
}
void CreateBitTree2(BitThrTree *T, char str[])
{
	
}


