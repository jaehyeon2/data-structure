#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//Stack 구조체 선언 (LinkedList)
typedef struct StackNode {
    int data;
    struct StackNode* next;
}StackNode;

//Stack 관련 함수
void pushLinkedStack(StackNode** top, int data);
StackNode* popLinkedStack(StackNode** top);
void showLinkedStack(StackNode* top);
StackNode* topLinkedStack(StackNode* top);
void deleteLinkedStack(StackNode** top);
int isEmpty(StackNode* top);

int main(){
    //가장 윗 부분을 가리키는 top 포인트 선언
    StackNode* top = NULL;
    StackNode* pNode;

    printf("Push(10, 20, 30) called.\n");
    pushLinkedStack(&top, 10);
    pushLinkedStack(&top, 20);
    pushLinkedStack(&top, 30);
    showLinkedStack(top);

    printf("Pop() called.\n");
    pNode=popLinkedStack(&top);
    if(pNode){
        free(pNode);
        showLinkedStack(top);
    }

    printf("Top() Called.\n");
    pNode=topLinkedStack(top);
    if(pNode){
        printf("Top node's data: %d\n", pNode->data);
    }
    else{
        printf("The Stack is empty\n");
    }
    showLinkedStack(top);

    deleteLinkedStack(&top);
    return 0;
}

int isEmpty(StackNode* top){
    if (top==NULL)
        return TRUE;
    else
        return FALSE;
}

void showLinkedStack(StackNode* top){
    StackNode *pNode=NULL;
    if (isEmpty(top)){
        printf("the Stack is empty\n");
    };

    pNode=top;
    printf("=========Show Stack=========\n");
    while (pNode!=NULL){
        printf("[%d]\n", pNode->data);
        pNode=pNode->next;
    }
    printf("============================\n");
}

void pushLinkedStack(StackNode** top, int data){
    StackNode *pNode=NULL;

    //넣을 Stack Node를 할당하고 data값을 저장
    pNode=(StackNode*)malloc(sizeof(StackNode));
    pNode->data=data;
    pNode->next=NULL;

    //만일 Stack이 empty일 경우 바로 top으로 지정
    if(isEmpty(*top)){
        *top=pNode;
    }
    //Stack에node가 하나라도 있을 경우 이어주기
    else{
        //넣을 Stack Node의 다음 노드가 현재의 top Node를 가리키고
        //top Node를 넣을 Stack Node로 지정
        pNode->next=*top;
        *top=pNode;
    }
}

StackNode* popLinkedStack(StackNode** top){
    StackNode *pNode=NULL;

    //Stack이 비어있는지 검사
    if (isEmpty(*top)){
        printf("the Stack is empty\n");
        return NULL;
    }
    //pNode에 top이 가리키는 Node를 지정하고 top은 그 다음 Node로 지정
    pNode=*top;
    *top=pNode->next;

    return pNode;
}

StackNode* topLinkedStack(StackNode* top){
    StackNode *pNode=NULL;

    if (!isEmpty(top)){
        pNode=top;
    }
    return pNode;
}

void deleteLinkedStack(StackNode** top){
    StackNode *pNode=NULL, *pDelNode=NULL;
    pNode=*top;

    //pNode를 한 칸씩 이동하면서 메모리 해제
    while(pNode!=NULL){
        pDelNode=pNode;
        pNode=pNode->next;
        free(pDelNode);
    }
    *top=NULL;
}