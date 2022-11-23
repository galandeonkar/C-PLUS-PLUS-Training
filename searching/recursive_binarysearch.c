//recursive

#include<stdio.h>

int binsearch(int arr[], int l, int r, int el)
{
    // int start = 0, end = n;
    int mid = (r + l)/2;

    while (l < r)
    {
        mid = (l + r)/2;

        if (arr[mid] == el)
        {
            return mid;
        }

        else if (arr[mid]>el)
        {
            return binsearch(arr,l,mid-1,el);
        }

        else
        {
            return binsearch(arr,mid+1,r,el);   
        }
    }

    return -1;

}

int main()
{
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the sorted array: ");
    for (int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &x);

    int result = binsearch(arr,0,n-1,x);

    if (result== -1)
    {
        printf("Element is not present in the array");
    }

    else
    {
        printf("Element is present at position %d",result+1);
    }

}

