#include <iostream>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

void minmaxRecursive(int *arr, int low, int high,  int &min, int &max) 
{
    if (low==high)
    {
        if (max<arr[low])
            max = arr[low];
        if (min>arr[high])
            min = arr[high];
        return;
    }

    if (high-low==1)
    {
        if (arr[low]<arr[high])
        {
            if (min>arr[low])
                min = arr[low];
            if (max<arr[high])
                max = arr[high];
        }

        else
        {
            if (min>arr[high])
                min = arr[high];
            if (max<arr[high])
                max = arr[high];
        }
        return;
    }

    int mid  = (low+high)/2;
    minmaxRecursive(arr,low,mid,min,max);
    minmaxRecursive(arr,mid+1,high,min,max);
}

int main()
{
    int n;
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

    int max = INT_MIN, min = INT_MAX;   
    minmaxRecursive(arr,0,n-1,min,max);
    cout<<"\nMinimum element in array: "<<min<<endl;
    cout<<"Maximum element in array: "<<max<<endl;
    return 0;
}

