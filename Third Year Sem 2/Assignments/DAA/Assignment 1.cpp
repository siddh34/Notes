#include<bits/stdc++.h>

// functions

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int arr[],int length){
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int j = high;
    int i = low + 1;

    do{
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            swap(&arr[i],&arr[j]);
        }

    }while(i < j);

    swap(&arr[low],&arr[j]);

    return j;
}

int Highpartition(int arr[],int low,int high){
    int pivot = arr[high];
    int j = low;
    int i = high - 1;

    do{
        while(arr[i] >= pivot){
            i--;
        }

        while(arr[j] < pivot){
            j++;
        }

        if(i > j){
            swap(&arr[i],&arr[j]);
        }

    }while(i > j);

    swap(&arr[high],&arr[j]);

    return j;
}

void quickSort(int arr[],int low,int high){
    int partitionIndex;
    if(low < high){
        // partitionIndex = partition(arr,low,high);  // sorts by taking pivot as first element
        partitionIndex = Highpartition(arr,low,high); // sorts by taking pivot as last element
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}

int main() {
    //type your code below
    int N;
    printf("Enter size of array: ");
    scanf("%d",&N);
    int arr[N];
    int length = sizeof(arr)/sizeof(arr[0]);

    printf("Enter element: \n");
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }


    printArray(arr,length);
    quickSort(arr,0,length - 1);
    printArray(arr,length);
    return 0;
}