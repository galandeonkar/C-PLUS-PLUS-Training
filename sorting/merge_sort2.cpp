#include<iostream>

using namespace std;

void merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;
    int temp[100];

    while(i<=mid && j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }

        else
        {
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while(j<=e)
    {
        temp[k++]=arr[j++];
    }

    for(int i=s;i<=e;i++)
    {
        arr[i]=temp[i];
    }
    return;
}

int mergeSort(int *arr, int beg, int end)
{
    int mid;
    if (beg<end)
    {
        mid = (beg+end)/2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, beg, end); 
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
    mergeSort(arr,0,n-1);
    cout<<endl;
    cout<<"\nArray after sorting: ";
    for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}