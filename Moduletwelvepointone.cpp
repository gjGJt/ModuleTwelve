  #include <iostream>
using namespace std;

// Functions  ( I used the names in the outline)
void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[], int left, int right);

 
void merge_sort(int arr[], int left, int right)
{
    int mid;
    if (left < right) {
        // Dividing array at mid and then sort
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        // Merging sorted arrays
        merge(arr, left, mid, right);
    }
}

// Merge function
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k, c[50];
    i = left;
    k = left;
    j = mid + 1;
    // using a temporary array to merge the two halves
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    // Copy remaining elements of left
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    // Copy remaining elements of right
    while (j <= right) {
        c[k] = arr[j];
        k++;
        j++;
    }
    // Copying the sorted elements to the original array
    for (i = left; i < k; i++) {
        arr[i] = c[i];
    }
}

// this is the main function
int main()
{
    int myarray[30], num;
    // Inputted number of elements to be sorted
    cout << "Enter number of elements to be sorted: ";
    cin >> num;
    // Inputted elements to be sorted
    cout << "Enter " << num << " elements to be sorted by spaces: ";
    for (int i = 0; i < num; i++) {
        cin >> myarray[i];
    }
    // Calling the merge_sort function for sorting the array
    merge_sort(myarray, 0, num - 1);
    // sorted array outputted
    cout << "Sorted array:\n";
    for (int i = 0; i < num; i++) {
        cout << myarray[i] << "\t";
    }
    cout << endl;
    return 0;
}


