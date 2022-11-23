#include <iostream>

using namespace std;

int countsort(int *arr,int n,int k)
{
    int count[k+1];

    //initialise all count to zero
    for (int i=0; i<k+1; i++)
    {
        count[i] = 0;
    }

    for (int i=0; i<n; i++)
    {
        ++count[arr[i]];
    }

    for (int i=1; i<=k; i++)
    {
        count[i] = count[i] + count[i-1];
    }

    int b[n];
    for (int i=n-1; i>=0; i--)
    {
        b[--count[arr[i]]] = arr[i];
    }

    for (int i=0; i<n; i++)
    {
        arr[i] = b[i];
    }

    for (int i=0; i<n; i++)
    {
        cout<<b[i]<<" ";
    }
}

int main()
{
    int n,k,ans;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of the array: ";
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    //finding highest val
    k = arr[0];
    for (int i=1; i<n; i++)
    {
        if (k<arr[i])
        {
            k = arr[i];
        }
    }

    countsort(arr,n,k);

    return 0;

}

