#include<iostream>
using namespace std;
//check recursively for sorted array
bool isSorted(int arr[], int n) {
    if (n == 0 || n == 1) {
        return arr[1] > arr[0];
    }

    return (arr[n - 1] > arr[n - 2]) & isSorted(arr, n - 1);
}
//increase the pointer and dec. the value of n
bool isSortedForward(int arr[], int n) {
    if (n == 1) return true;
    return arr[0] < arr[1] & isSortedForward(arr + 1, n - 1);
}

int firstOc(int arr[], int n, int i, int key) {

    if (i == n) {
        return -1;
    }
    if (arr[i] == key) {
        return i;
    }
    return firstOc(arr, n, i + 1, key);
}

int lastOccur(int arr[], int n, int i, int key) {
    if (i == n)
        return -1;
    int rest = lastOccur(arr, n, i + 1, key);
    if (rest != -1) return rest;
    if (arr[i] == key) {
        return i;
    }
    return -1;
}

int main() {
    int n,key;
    cin >> n>>key;
    int arr[n];
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cout << lastOccur(arr, n, 0, key);
}