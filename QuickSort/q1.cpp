#include <iostream>
using namespace std;

// Partition function (same as Quick Sort)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quickselect function to find k-th smallest
int kthSmallest(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi + 1 == k)  // pivot is the k-th smallest
            return arr[pi];
        else if (pi + 1 > k) // k-th element is in left subarray
            return kthSmallest(arr, low, pi - 1, k);
        else                 // k-th element is in right subarray
            return kthSmallest(arr, pi + 1, high, k);
    }
    return -1; // not found (should not happen)
}

int main() {
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;

    int result = kthSmallest(arr, 0, n - 1, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
