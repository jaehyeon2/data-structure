#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
}Node;


void insertTreeNode(Node** p, int value);
void printTreePreorder(Node* pNode);
void printTreeInorder(Node* pNode);
void printTreePostorder(Node* pNode);

Node* searchTreeNode(Node* p, int value);
Node* searchTreeParentNode(Node* p, int value);
void deleteTreeNode(Node** p, int value);

int main(){
	Node* pParentNode=NULL;

	insertTreeNode(&pParentNode, 4);
    insertTreeNode(&pParentNode, 2);
    insertTreeNode(&pParentNode, 6);
    insertTreeNode(&pParentNode, 1);
    insertTreeNode(&pParentNode, 3);
    insertTreeNode(&pParentNode, 5);
    insertTreeNode(&pParentNode, 7);

    printf("Tree(pParentNode)\n");
    printf("Preorder\t:");
    printTreePreorder(pParentNode);
    printf("\nInorder\t\t:");
    printTreeInorder(pParentNode);
    printf("\nPostorder\t:");
    printTreePostorder(pParentNode);
    printf("\n\n");

    printf("Search Data 3\n");
    if (searchTreeNode(pParentNode, 3)!=NULL){
        printf("3 is existed\n\n");
    }
    else{
        printf("3 is not existed\n\n");
    }

    printf("Delete data 2\n");
    deleteTreeNode(&pParentNode, 2);
    printf("\nDelete data 3\n");
    deleteTreeNode(&pParentNode, 3);
    
    printf("\nSearch Data 3\n");
    if(searchTreeNode(pParentNode, 3)!=NULL){
        printf("3 is existed\n\n");
    }
    else{
        printf("3 is not existed\n\n");
    }

    printf("Tree(pParentNode)\n");
    printf("Preorder\t:");
    printTreePreorder(pParentNode);
    printf("\nInorder\t\t:");
    printTreeInorder(pParentNode);
    printf("\nPostorder\t:");
    printTreePostorder(pParentNode);
    printf("\n\n");

    return 0;
}

void insertTreeNode(Node** p, int value){
    if((*p)==NULL){
        //Create TreeNode with value
        (*p)=(Node*)malloc(sizeof(Node));
        (*p)->data=value;
        (*p)->leftChild=NULL;
        (*p)->rightChild=NULL;
    }
    else if((*p)->data>value){
        //Recursive call to leftChild
        insertTreeNode(&((*p)->leftChild), value);
    }
    else{
        //Recursive call to rightChild
        insertTreeNode(&((*p)->rightChild), value);
    }
}

void printTreePreorder(Node* pNode)
{
    if (pNode==NULL){
        return;
    }

    printf("%3d", pNode->data);
    printTreePreorder(pNode->leftChild);
    printTreePreorder(pNode->rightChild);
}

void printTreeInorder(Node* pNode){
    if (pNode==NULL){
        return;
    }

    printTreeInorder(pNode->leftChild);
    printf("%3d", pNode->data);
    printTreeInorder(pNode->rightChild);
}

void printTreePostorder(Node* pNode){
    if (pNode==NULL){
        return;
    }

    printTreePostorder(pNode->leftChild);
    printTreePostorder(pNode->rightChild);
    printf("%3d", pNode->data);
}

Node* searchTreeNode(Node* p, int value){
    //p 노드의 데이터가 value와 같을 때까지 탐색
    while(p!=NULL&&p->data!=value){
        //현재 p 노드의 데이터와 같지 않을 경우
        //BST의 원리에 맞게 탐색
        if (p->data<value){
            p=p->rightChild;
        }
        else if (p->data>value){
            p=p->leftChild;
        }
    }
    //찾았으면 해당 노드의 주소를 반환
    //못 찾았으면 NULL을 반환
    return p;
}

Node* searchTreeParentNode(Node* p, int value){
    //p 노드의 직전 노드인 부모노드 변수
    Node* parentNode=NULL;
    //p 노드의 데이터가 value와 같을 때까지 탐색
    while (p!=NULL&&p->data!=value){
        //부모 노드가 p 노드를 가리키고
        //p 노드는 다음 자식 노드로 이동
        parentNode=p;
        if (p->data<value){
            p=p->rightChild;
        }
        else{
            p=p->leftChild;
        }
    }
    return parentNode;
}

Node* findMinNode(Node* p){
    Node* tmp=p;
    while(tmp->leftChild!=NULL){
        tmp=tmp->leftChild;
    }
    return tmp;
}

void deleteTreeNode(Node** p, int value){
    Node* parentNode;
    Node* delNode;
    Node* childNode;
    Node* succNode;

    parentNode=searchTreeParentNode(*p, value);
    delNode=searchTreeNode(*p, value);
    if (delNode==NULL){
        printf("There is no %d\n", value);
        return ;
    }

    //Case 1. no children node
    if((delNode->leftChild==NULL)&&(delNode->rightChild==NULL)){
        //지울 노드가 root 노드일 경우
        if (parentNode==NULL){
            (*p)=NULL;
        }
        
        //지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 NULL로 지정
        else if (parentNode->leftChild==delNode){
            parentNode->leftChild=NULL;    
        }
        else{
			parentNode->rightChild=NULL;
        }
        free(delNode);
    }

    //Case 2. one child node
    else if((delNode->leftChild==NULL)||(delNode->rightChild==NULL)){
        //지울 노드의 자식 노드를 childNode변수를 이용해 가리키도록 함
        childNode=(delNode->leftChild!=NULL)?delNode->leftChild:delNode->rightChild;
        if(parentNode==NULL){
            (*p)=childNode;
        }
        else{
            //지울 노드가 부모 노드의 어느 쪽에 있는지 확인하고 자식 노드를 연결
            if(parentNode->leftChild==delNode){
                parentNode->leftChild=childNode;
            }
            else{
                parentNode->rightChild=childNode;
            }
        }
        free(delNode);
    }

    //Case 3. two child node
    else{
        succNode=findMinNode(delNode->rightChild);
        delNode->data=succNode->data;
        deleteTreeNode(&(delNode->rightChild), succNode->data);
    }
}