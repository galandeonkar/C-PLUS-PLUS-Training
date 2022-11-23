//aaaaaaaaaaaaaa

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main(void)
{
    int n,data;
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
    
    cout<<"\nEnter the data to be searched: ";
    cin>>data;
    int result = binarySearch(arr, 0, n - 1, data);
    if (result==-1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << result;
    return 0;
}
