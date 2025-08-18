#include <iostream>
using namespace std;

void merge(int arr[], int index[], int count[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];   // temporary value arrays
    int Li[100], Ri[100]; // temporary index arrays

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        Li[i] = index[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        Ri[j] = index[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    int rightCount = 0; // number of smaller elements from right taken

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            // all right elements taken so far are smaller than L[i]
            count[Li[i]] += rightCount;
            arr[k] = L[i];
            index[k] = Li[i];
            i++;
        } else {
            // R[j] is smaller → increase rightCount
            rightCount++;
            arr[k] = R[j];
            index[k] = Ri[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        count[Li[i]] += rightCount;
        arr[k] = L[i];
        index[k] = Li[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        index[k] = Ri[j];
        j++; k++;
    }
}

void mergeSort(int arr[], int index[], int count[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, index, count, left, mid);
    mergeSort(arr, index, count, mid + 1, right);
    merge(arr, index, count, left, mid, right);
}

int main() {
    int arr[6] = {5, 2, 6, 1};  // input array
    int n = 4;

    int index[100], count[100];
    for (int i = 0; i < n; i++) {
        index[i] = i;
        count[i] = 0;
    }

    mergeSort(arr, index, count, 0, n - 1);

    cout << "Result: [ ";
    for (int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}
