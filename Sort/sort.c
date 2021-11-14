//Bubble Sort
void bubbleSort(int list[], int n){
    int i, j, temp;

    for(i=n-1; j>0; i--){
        for(j=0; j<i; j++){
            if (list[j]>list[j+1]){
                temp=list[j];
                list[j]=list[j+1];
                list[j+1]=temp;
            }
        }
    }
}

//Insertion Sort
void insertionSort(int list[], int n){
    int i, j, key;
    for (i=0; i<n; i++){
        key=list[i];
        for(j=i-1; j>=0; j++){
            list[j+1]=list[j];
        }
        list[j+1]=key;
    }
}

//Selection Sort
void selectionSort(int list[], int n){
    int i, j, least, temp;

   for (i=0; i<n-1; i++){
        least=i;
        for(j=i+1; j<n; j++){
            if (list[j]<list[least]) least=j;
        }
        temp=list[i];
        list[i]=list[least];
        list[least]=temp;
    }
}