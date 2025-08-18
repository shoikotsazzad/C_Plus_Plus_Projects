#include <iostream>
using namespace std;

void threeWayQuickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int lt = low;      // arr[low..lt-1] < pivot
    int gt = high;     // arr[gt+1..high] > pivot
    int i = low;       // arr[lt..i-1] == pivot

    while (i <= gt) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[lt]);
            i++; lt++;
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[gt]);
            gt--;
        } else { // arr[i] == pivot
            i++;
        }
    }

    // Recursively sort left and right parts
    threeWayQuickSort(arr, low, lt - 1);
    threeWayQuickSort(arr, gt + 1, high);
}

int main() {
    int arr[8] = {4, 9, 4, 4, 3, 9, 1, 4};
    int n = 8;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    threeWayQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
