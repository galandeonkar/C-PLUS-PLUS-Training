#include <iostream>
// #include <chrono>

using namespace std;
// using namespace std::chrono;

int searchingSort(int *arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }

            if (min != i)
            {
                swap(arr[i], arr[min]);
            }
        }
    }
}

int binarySearch(int *arr, int l, int r, int data)
{
    int mid = (l+r)/2;
    while (l<r)
    {
        int mid = (l+r)/2;
        if (data==arr[mid])
            return mid;
        else if (data>arr[mid])
            return binarySearch(arr,mid+1,r,data);
        else
            return binarySearch(arr,l,mid-1,data);
    }

    return -1;
}

int main()
{
    int n, data;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
      arr[i]=rand()%100;

    cout<<"Array: ";
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }

    searchingSort(arr,n);
    cout<<"\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
    }
    
    cout<<"\nEnter the data to be searched: ";
    cin>>data;
    
    int result = binarySearch(arr,0,n-1,data);

    cout<<"Element is found at index: "<<result;

 
}