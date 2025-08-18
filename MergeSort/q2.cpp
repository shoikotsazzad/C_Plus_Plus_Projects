#include <iostream>
using namespace std;

// Merge two sorted arrays arr1 (size n1) and arr2 (size n2) into result[]
void mergeTwoArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < n1) result[k++] = arr1[i++];
    while (j < n2) result[k++] = arr2[j++];
}

// Merge K sorted arrays using divide & conquer
void mergeKArrays(int arr[][100], int k, int n, int output[]) {
    // Temporary arrays
    int temp1[1000], temp2[1000];  

    // Copy first array into temp1
    for (int i = 0; i < n; i++) temp1[i] = arr[0][i];
    int size = n;

    // Merge arrays one by one
    for (int i = 1; i < k; i++) {
        mergeTwoArrays(temp1, size, arr[i], n, temp2);

        // Copy back into temp1 for next merge
        size += n;
        for (int j = 0; j < size; j++) temp1[j] = temp2[j];
    }

    // Final result in output[]
    for (int i = 0; i < size; i++) output[i] = temp1[i];
}

int main() {
    // Example input: k=3 arrays, n=3 each
    int k = 3, n = 3;
    int arr[3][100] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int output[1000];
    mergeKArrays(arr, k, n, output);

    cout << "Merged array: ";
    for (int i = 0; i < k * n; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}
