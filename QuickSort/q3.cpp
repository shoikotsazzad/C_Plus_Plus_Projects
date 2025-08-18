#include <iostream>
using namespace std;

// Global variable to count swaps
int swapCount = 0;

// Partition function (Quick Sort style)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCount++; // increment swap count
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++; // swap pivot into place
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[6] = {5, 1, 8, 3, 9, 2};
    int n = 6;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "Number of swaps: " << swapCount << endl;

    return 0;
}
