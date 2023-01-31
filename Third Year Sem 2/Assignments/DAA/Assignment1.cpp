#include<bits/stdc++.h>
using namespace std;

// Author: Siddharth Sutar
// Date: 18 January 2023

// functions

void printArray(int arr[],int length){
    for(int i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// quick sort functions

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
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

// merge sort functions

void merge(int arr[],int low,int mid, int high){
    int i, j, k;
    int* Brr = (int *)malloc((high - low + 10)*sizeof(int)); 
    i = low;
    j = mid + 1;
    k = low;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            Brr[k] = arr[i];
            i++;
            k++;
        }else{
            Brr[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        Brr[k] = arr[i];
        i++;
        k++;
    }

    while(j <= high){
        Brr[k] = arr[j];
        j++;
        k++;
    }

    // copying Brr's elements to arr

    for(int i = low; i <= high; i++){
        arr[i] = Brr[i];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main() {
    //type your code below
    int N;
    // printf("Enter size of array: ");
    scanf("%d",&N);
    int arr[N];
    int length = sizeof(arr)/sizeof(arr[0]);

    // printf("Enter element: \n");
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }

    int choice;
    // printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        // printArray(arr,length);
        quickSort(arr,0,length - 1);
        printArray(arr,length);
        break;
    case 2:
        // printArray(arr,length);
        mergeSort(arr,0,length - 1);
        printArray(arr,length);
        break;
    default:
        printf("Wrong Choice");
        break;
    }

    return 0;
}