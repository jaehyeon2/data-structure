#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE -1
#define TRUE 1

//List의 기본 구성단위인 Node
typedef struct Node {
	int data;
	struct Node* nextNode;
}Node;

typedef struct LinkedList {
	int curCount;			//현재 List에 들어있는 Node의 갯수 
	Node headNode;			//List의 시작 Node 
}LinkedList;

int addNode(LinkedList* pList, int pos, int data);
int removeNode(LinkedList* pList, int pose);
void showNode(LinkedList* pList);
int isEmpty(LinkedList* pList);
int findPos(LinkedList* pList, int data);
void makeEmpty(LinkedList* pList);

int main()
{
	int pos;
	
	//Singular Linked List 생성
	LinkedList* linkedList=(LinkedList*)malloc(sizeof(LinkedList));
	linkedList->curCount=0;
	linkedList->headNode.nextNode=NULL;
	
	showNode(linkedList);
	
	addNode(linkedList, 0, 10);
	addNode(linkedList, 5, 100);
	addNode(linkedList, 1, 20);
	addNode(linkedList, 2, 30);
	addNode(linkedList, 1, 50);
	
	showNode(linkedList);
	
	removeNode(linkedList, 1);
	showNode(linkedList);

    pos=findPos(linkedList, 30);
    printf("the location of node with data '30':%d\n", pos);

    makeEmpty(linkedList);
    showNode(linkedList);
    return 0;
}

//출력 함수 구현
void showNode(LinkedList* pList)
{
    int i=0;
    Node *pNode=NULL;

    if(pList==NULL)
    {
        printf("showNode() error\n");
        return ;
    }

    printf("현재 Node 개수: %d \n", pList->curCount);
    pNode=pList->headNode.nextNode;

    while (pNode!=NULL)
    {
        printf("[%d]\n", pNode->data);
        pNode=pNode->nextNode;
    }
    printf("--------------------\n");
}

//Linked List 내부 Node가 존재하는지 확인하는 함수 구현
int isEmpty(LinkedList* pList){
    if (pList==NULL){
        printf("isEmpty() Error\n");
        return -1;
    }
    if (pList->headNode.nextNode==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int addNode(LinkedList* pList, int pos, int data){
    int i=0;
    Node* pNewNode=NULL, *pTmpNode=NULL;
    if(pList==NULL)
    {
        printf("addNode() error\n");
        return FALSE;
    }
    if (pos<0||pos>pList->curCount){
        printf("addNode() error2:추가 범위 초과\n");
        return FALSE;
    }
    pNewNode=(Node*)malloc(sizeof(Node));
    if(!pNewNode){
        printf("addNode() error3 \n");
        return FALSE;
    }

    pNewNode->data=data;
    pNewNode->nextNode=NULL;

    //추가될 위치 직전 노드로 이동
    pTmpNode=&(pList->headNode);    //pTmpNode는 포인터이다.
    for(i=0; i<pos; i++){
        pTmpNode=pTmpNode->nextNode;
    }

    //추가 노드의 nextNode=직전 노드의 nextNode
    //직전 노드의 nextNode=추가 노드의 주소
    pNewNode->nextNode=pTmpNode->nextNode;
    pTmpNode->nextNode=pNewNode;
    pList->curCount++;
}

int removeNode(LinkedList* pList, int pos){
    int i=0;
    Node* pDelNode=NULL, *pTmpNode=NULL;

     if(pList==NULL)
    {
        printf("removeNode() error\n");
        return FALSE;
    }
    if (pos<0||pos>pList->curCount){
        printf("removeNode() error2:삭제 범위 초과\n");
        return FALSE;
    }

    //삭제될 노드 직전 위치로 이동
    pTmpNode=&(pList->headNode);
    for(i=0; i<pos; i++){
        pTmpNode=pTmpNode->nextNode;
    }
    
    //삭제할 노드=직전 노드의 nextNode
    //직전 노드의 nextNode=삭제할 노드의 nextNode
    pDelNode=pTmpNode->nextNode;
    pTmpNode->nextNode=pDelNode->nextNode;
    free(pDelNode);
    pList->curCount--;
    return TRUE;
}

int findPos(LinkedList* pList, int data){
    int pos=0;
    Node* pNode=NULL;
    if(pList==NULL){
        printf("findPos() error\n");
        return FALSE;
    }

    pNode=pList->headNode.nextNode;
    //마지막 노드까지 탐색
    while(pNode!=NULL){
        if(pNode->data==data)
            return pos;
        pos++;
        pNode=pNode->nextNode;
    }
    return FALSE;
}

void makeEmpty(LinkedList* pList){
    Node* pDummyNode=NULL, *pTmpNode=NULL;
    if(pList!=NULL){
        pTmpNode=pList->headNode.nextNode;
        //연결되어 있는 모든 노드를 탐색
        while(pTmpNode!=NULL){
            //Dummy Node는 지우기 위한 노드
            //Tmp Node는 이동하기 위한 노드
            pDummyNode=pTmpNode;
            pTmpNode=pTmpNode->nextNode;
            free(pDummyNode);
        }
        pList->headNode.nextNode=NULL;
    }
}

