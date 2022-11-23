#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int insertionSort(int *arr, int n)
{
    int temp,j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout <<arr[i]<<" ";
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

    auto start = high_resolution_clock::now();
    insertionSort(arr,n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout<<"\nTime taken for execution: ";
    cout << duration.count() << endl;
}