#include <iostream>

using namespace std;

int Partition(int *arr,int lb,int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (arr[start]<=pivot) 
        {
            start++;
        }
        while (arr[end]>pivot) 
        {
            end--;
        }
        if (start<end)
        {
            swap(arr[start],arr[end]);
        }
    }

    swap(arr[lb],arr[end]);
    return end;
}

int QuickSort(int *arr,int lb,int ub)
{
    if (lb<ub)
    {
        int loc = Partition(arr,lb,ub);
        QuickSort(arr,lb,loc-1);
        QuickSort(arr,loc+1,ub);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)    
      arr[i]=rand()%100;

    cout<<"\nArray before sorting: ";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    QuickSort(arr,0,n-1);

    cout<<endl;
    cout<<"\nArray after sorting: ";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}