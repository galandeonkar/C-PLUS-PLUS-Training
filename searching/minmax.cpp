#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int min_max(int *arr, int n)
{
    int i = 0;
    int max, min;
    max = min = arr[i];

    for (int i=1;i<n;i++) 
    {
        if (arr[i]>max) 
            max = arr[i];
        if (arr[i]<min)
            min = arr[i];
    }

    cout<<"\nMinimum element in array: "<<min<<endl;
    cout<<"Maximum element in array: "<<max<<endl;
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

    auto start = high_resolution_clock::now();
    min_max(arr,n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout<<"\nTime taken for execution: ";
    cout << duration.count() << endl;
}