#include<stdio.h>
#include<stdlib.h>

int list[7]={38, 27, 43, 3, 9, 82, 10};

int partition(int list[], int start, int end){
    int temp;
    int pivot=start;
    int left=start+1;
    int right=end;

    while (left<=right){
        while(left<=end && list[left]<=list[pivot]){
            left+=1;
        }
        while(right>start && list[right]>=list[pivot]){
            right-=1;
        }
        if(left>right){
            temp=list[right];
            list[right]=list[pivot];
            list[pivot]=temp;
            pivot=right;
        }
        else{
            temp=list[left];
            list[left]=list[right];
            list[right]=temp;
        }
    }
    return pivot;
}

void quickSort(int list[], int left, int right){
    if (left<right){
        int q=partition(list, left, right);
        quickSort(list, left, q-1);
        quickSort(list, q+1, right);
    }
}

int main(){
    int i=0;
    quickSort(list, 0, 6);

    for (i=0; i<7; i++){
        printf("%d  ", list[i]);
    }

    printf("\n");

    return 0;
}