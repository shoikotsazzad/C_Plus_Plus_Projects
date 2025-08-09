#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = (high + low) / 2;

        if (arr[mid] == key) {
            return mid;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;  // Return -1 if key is not found
}

int main() {
    int arr[] = {5, 8, 12, 25, 29, 36};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int result = binarySearch(arr, n, key);
    
    if (result != -1) {
        cout << "Index is: " << result << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
