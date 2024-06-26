#include <bits/stdc++.h>
using namespace std;
                                            /// quick sort works on divide and conquer, where it has a pivot that is first element , using which we do the partition and find the partition index.
                                            /// The left side of partition index is small (unsorted for first partiton) and the right side of partion index is large (unsorted for first partiton)
int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = arr[low];                    /// everytime the pivot is first element 
    int i = low - 1;                         /// i is outside array before the first element
    int j = high + 1;                        /// j is outside array after the last element

    while (true)
    {
        do
        {
            i++;                            /// i represents the left side of partition index, left side of partition index are small  === [5(i) , 3 , 7 , 2 , 8 , 4(j)]
        } while (arr[i] < pivot);           /// i increments , if it finds any element greater then pivot it will break the loop to swap with smaller element that j found  === [4(i) , 3 , 7 , 2 , 8 , 5(j)]

        do
        {
            j--;                            /// j represents the right side of partition index, left side of partition index are greater === [5(i) , 3 , 7 , 2 , 8 , 4(j)]
        } while (arr[j] > pivot);           /// j decrements , if it finds any element smaller then pivot it will break the loop to swap with greater element that i found  === [4(i) , 3 , 7 , 2 , 8 , 5(j)]

        if (i >= j)
            return j;                       /// when i crosses j then the index j is the partition index  === [4 , 3 , 2(j) , 7(i) , 8 , 5]

        temp = arr[j];                      /// swapping of arr[i] and arr[j]
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);  /// partition index

        quicksort(arr, low, pi);            /// sorts by partition function for left side of partition index
        quicksort(arr, pi + 1, high);        /// sorts by partition function for right side of partition index
    }
}

int main()
{
    int arr[1000], i, n;
    cout << "Enter number of elements :\n";
    cin >> n;
    cout << "Enter " << n << " elements:\n";

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
