#include <iostream>

using namespace std;

void displayArray(int *arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void selectionSort(int *arr,int size)
{
    for(int i = 0;i<size;i++)
    {
        int minimum = i;
        
        for(int j = i+1;j<size;j++)
        {
            if(arr[j] < arr[minimum])
            {
                minimum = j;
            }
        }
        
        arr[i] = (arr[i] + arr[minimum]) - (arr[minimum] = arr[i]);
    }
}

void bubbleSort(int *arr,int size)
{
    for(int i = 0;i<size-2;i++)
    {
        for(int j = 0;j<size-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j] = (arr[j] + arr[j+1]) - (arr[j+1] = arr[j]);
            }

        }
    }
}

void insertionSort(int *arr,int size)
{
    for(int i = 1;i<size;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}

void merge(int *arr,int start,int mid,int end)
{
    int leftSize  = mid - start + 1;
    int rightSize = end - mid;
    int tempStart = start;
    
    int leftArray[leftSize+1];
    int rightArray[rightSize+1];
    
    for(int i = 0;i<leftSize;i++)
    {
        leftArray[i] = arr[tempStart++];
    }
    
    for(int i = 0;i<rightSize;i++)
    {
        rightArray[i] = arr[++mid];
    }
    
    leftArray[leftSize] = rightArray[rightSize] = 32767;
    
    int i = 0;
    int j = 0;
    for(int k = start;k<=end;k++)
    {
        if(leftArray[i] > rightArray[j])
        {
            arr[k] = rightArray[j++];
        }
        else
        {
            arr[k] = leftArray[i++];
        }
    }
}

void mergeSort(int *arr,int start,int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}


int partition(int *arr,int start,int end)
{
   int key = arr[end];
   int i = start - 1;
   for(int j = start;j<=end;j++)
   {
       if(arr[j] < key)
       {
           ++i;
           arr[i] = (arr[i] + arr[j])-(arr[j] = arr[i]);
       }
   }
   arr[i+1] = (arr[i+1] + arr[end]) - (arr[end] = arr[i+1]);
   
   return i+1;
}

void quickSort(int *arr,int start,int end)
{
    if(start < end)
    {
        int split = partition(arr,start,end);
        quickSort(arr,start,split-1);
        quickSort(arr,split+1,end);
    }
}

int main()
{
    int arr[] = {10,7,12,4,3,5,9};
    int size  = sizeof(arr)/sizeof(arr[0]);
    
    // cout<<"Selection Sort"<<endl;
    // selectionSort(arr,size);
    
    // cout<<"Bubble Sort"<<endl;
    // bubbleSort(arr,size);
    
    // cout<<"Insertion Sort"<<endl;
    // insertionSort(arr,size);
    
    cout<<"Merge Sort"<<endl;
    mergeSort(arr,0,size-1);
    
    cout<<"Quick Sort"<<endl;
    quickSort(arr,0,size-1);
    displayArray(arr,size);
    return 0;
}