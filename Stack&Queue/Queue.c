#include <stdio.h>
#include <stdlib.h>

#define Capacity 5
#define TRUE 1
#define FALSE 0

//Circular Queue 구조체 선언
typedef struct circularQueue{
    int data[Capacity];         //ArrayList data 선언
    int front;                  //Circular Queue의 앞부분
    int rear;                   //Circular Queue의 마지막 부분
}cQueue;

//Circular Queue 함수
cQueue* createCircularQueue();
void enqueue(cQueue* cQueue, int data);
int isFull(cQueue* cQueue);
void showQueue(cQueue* cQueue);
int isEmpty(cQueue* cQueue);
void dequeue(cQueue* cQueue);

int main(){
    cQueue* cQueue;
    //Circular Queue 초기화
    cQueue=createCircularQueue();
    printf("initial\n");

    printf("front:%d, rear:%d\n\n", cQueue->front, cQueue->rear);

    printf("enqueue data 10\n");
    enqueue(cQueue, 10);
    printf("enqueue data 20\n");
    enqueue(cQueue, 20);
    printf("enqueue data 30\n");
    enqueue(cQueue, 30);
    showQueue(cQueue);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);

    printf("dequeue\n");
    printf("dequeue\n");
    dequeue(cQueue);
    dequeue(cQueue);
    showQueue(cQueue);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);

    printf("enqueue data 40\n");
    enqueue(cQueue, 40);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);
    printf("enqueue data 50\n");
    enqueue(cQueue, 50);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);
    printf("enqueue data 60\n");
    enqueue(cQueue, 60);
    showQueue(cQueue);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);
    printf("enqueue data 70\n");
    enqueue(cQueue, 70);
    printf("front:%d, rear:%d\n", cQueue->front, cQueue->rear);
    showQueue(cQueue);
    return 0;
}

//비어있는 Queue를 생성
cQueue* createCircularQueue(){
    cQueue* pCQueue=NULL;
    int i;
    //메모리 상에 Queue를 할당시키고 이를 반환
    pCQueue=(cQueue *)malloc(sizeof(cQueue));
    pCQueue->front=0;
    pCQueue->rear=0;

    return pCQueue;
}

void enqueue(cQueue* cQueue, int data){
    if (isFull(cQueue)==TRUE){
        printf("Circular Queue is full!\n");
        return;
    }
    //Circular Queue의 뒷부분에 data를 추가
    cQueue->rear=(cQueue->rear+1)%Capacity;
    cQueue->data[cQueue->rear]=data;
}

void dequeue(cQueue* cQueue){
    if (isEmpty(cQueue)==TRUE){
        printf("Circular Queue is Empty!\n");
        return;
    }
    //Circular Queue의 앞 부분을 다음 칸으로 이동
    cQueue->front=(cQueue->front+1)%Capacity;
}

void showQueue(cQueue* cQueue){
    int i;
    if(isEmpty(cQueue)==TRUE){
        printf("Circular Queue is Empty!\n");
        return;
    }
    printf("========show queue========\n");
    for (i=cQueue->front+1; i!=cQueue->rear; i=(i+1)%Capacity){
        printf("[%d]\n", cQueue->data[i]);
    }
    printf("[%d]\n", cQueue->data[i]);
    printf("==========================\n");
}

int isFull(cQueue* cQueue){
    if((cQueue->rear+1)%Capacity==cQueue->front){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int isEmpty(cQueue* cQueue){
    if(cQueue->front==cQueue->rear){
        return TRUE;
    }
    else{
        return FALSE;
    }
}