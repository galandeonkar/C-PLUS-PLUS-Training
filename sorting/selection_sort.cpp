#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    searchingSort(arr,n);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout<<"\nTime taken for execution: ";
    cout << duration.count() << endl;
}