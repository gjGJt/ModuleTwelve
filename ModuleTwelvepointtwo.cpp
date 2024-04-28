/*Pivot- A  pivot element is selected from the array, which is used to partition thae array into sub-arrays.
 The algorithm iterates through the array, placing elements smaller than the pivot to the left and elements greater than the pivot to the right.
Recursion--When the partitioning is complete, the sub-arrays are recursively sorted.
Combining Sub-Arrays--- Once the sort is complete, the sub-arrays are combined.*/

#include <iostream>
using namespace std;

// Swap two elements
void swap(int* a, int* b)
{
    // Swap the values of two integer pointers.
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition the array
int partition(int arr[], int low, int high)
{
    // Pivot element.
    int pivot = arr[high];    // Set the pivot as the last element of the array.
    int i = (low - 1);

    // Iterate through the array
    for (int j = low; j <= high - 1; j++)
    {
        // Checks if the current element is smaller than or equal to the pivot, move it to the left side.
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]); // Swap the elements
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index.
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int size)
{
    // To display the elements of the array.
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements separated by spaces: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Input array" << endl;
    displayArray(arr, n);
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Array sorted with quick sort" << endl;
    displayArray(arr, n);

    return 0; 
}

