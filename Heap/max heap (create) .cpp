#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int root)            // converts an array in to heap (max heap)
{
    int temp;
    int largest = root;                             // largest element is the current root
    int l = 2 * root + 1;                           // left child
    int r = 2 * root + 2;                           // right child

    if (l < n && arr[l] > arr[largest])             // check if left child is greater then root .( l < n , so that checking left child doesnot go out of bound )
    {
        largest = l;                                // if it is, then largest variable will keep the index of left child
    }
    if (r < n && arr[r] > arr[largest])             // do the same for right child ...
    {
        largest = r;                                // ...
    }


    if (largest != root)                            // base case for recursion. largest variable will remain same only when the recursion goes out of bound . ie when r or l > n
    {
        temp = arr[largest];
        arr[largest] = arr[root];                   // swap root with largest child
        arr[root] = temp;

        heapify(arr, n, largest);                   // recursively check if the largest child of the current root also has any large child within the bound
    }
}

void buildheap(int arr[], int n)
{
    int strt_idx = (n / 2) - 1;                     // every element after index (n/2)-1 is non leaf (have no child and are considered as heap elements) so we start iteration from (n/2)-1

    for (int i = strt_idx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements in to heap:";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    buildheap(arr, n);
    cout << "The maxheap elements are" << endl;
   

    return 0;
}
