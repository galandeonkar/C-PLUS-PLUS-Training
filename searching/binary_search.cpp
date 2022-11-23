#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int binarySearch(int *arr, int n, int data)
{   
    int l,r,mid,pos;
    l = 0, r = n-1;
    while (l<r) 
    {
        mid = (l+r)/2;

        if (data == arr[mid]) 
            return mid;
        else if (data < arr[mid])
            r = mid-1;
        else
            l = mid+1;
    }

    return -1;
}

int main()
{
    int n, data;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements in the array: ";
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    cout<<"Enter the data to be searched: ";
    cin>>data;

    auto start = high_resolution_clock::now();
    int result = binarySearch(arr,n,data);
    auto end = high_resolution_clock::now();
    
    if (result== -1)
    {
        cout<<"Element is not present in the array";
    }

    else
    {
        cout<<"Element is present at position: "<<result+1;
    }

    auto duration = duration_cast<nanoseconds>(end - start);
    cout<<"\nTime taken for execution: ";
    cout << duration.count() << endl;
}