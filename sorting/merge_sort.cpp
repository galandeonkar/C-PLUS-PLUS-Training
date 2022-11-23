#include<iostream>

using namespace std;

void merge(int *arr, int beg, int mid, int end)
{
    int i,j,k;
    int a = mid-beg+1;
    int b = end-mid;

    int LeftArr[a], RightArr[b];
    for (int i=0; i<a; i++)
        LeftArr[i] = arr[beg+i];
    for (int j=0; i<b; i++)
        RightArr[j] = arr[mid+j+1];

    i = beg, j=mid+1, k=end;

    while (i<a and j<b)
    {
        if (LeftArr[i]<=RightArr[j])
        {
            arr[k] = LeftArr[i];
            i++;
        }

        else
        {
            arr[k] = RightArr[j];
            j++;
        }
        k++;
    }

    while (i<a)
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j<b)
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }
}

int mergeSort(int *arr, int beg, int mid, int end)
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