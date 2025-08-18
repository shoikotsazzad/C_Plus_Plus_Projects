#include <iostream>
using namespace std;

double findMedian(int arr1[], int n1, int arr2[], int n2) {
    int total = n1 + n2;
    int mid1 = (total - 1) / 2;  // first middle index
    int mid2 = total / 2;        // second middle index (same as mid1 if odd)

    int i = 0, j = 0, count = 0;
    int curr, prev;

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            prev = curr;
            curr = arr1[i++];
        } else {
            prev = curr;
            curr = arr2[j++];
        }

        if (count == mid2) {
            if (total % 2 == 0)
                return (prev + curr) / 2.0;
            else
                return curr;
        }
        count++;
    }

    // If elements remain in arr1
    while (i < n1) {
        prev = curr;
        curr = arr1[i++];

        if (count == mid2) {
            if (total % 2 == 0)
                return (prev + curr) / 2.0;
            else
                return curr;
        }
        count++;
    }

    // If elements remain in arr2
    while (j < n2) {
        prev = curr;
        curr = arr2[j++];

        if (count == mid2) {
            if (total % 2 == 0)
                return (prev + curr) / 2.0;
            else
                return curr;
        }
        count++;
    }

    return -1; // should not reach
}

int main() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    int n1 = 3, n2 = 3;

    cout << "Median = " << findMedian(arr1, n1, arr2, n2) << endl;

    return 0;
}
