#include <iostream>
using namespace std;

bool isSumK(int arr[], int n, int k, int s, int subset[], int& subsetSize) {
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
        int sum = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += arr[i];
                subset[count++] = arr[i];
            }
        }
        if (count == k && sum == s) {
            subsetSize = count;
            return true;
        }
    }
    return false;
}

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = 5, k = 3, s = 9;
    int subset[10], subsetSize = 0;

    if (isSumK(arr, n, k, s, subset, subsetSize)) {
        cout << "True (because ";
        for (int i = 0; i < subsetSize; i++) {
            cout << subset[i];
            if (i < subsetSize - 1) cout << " + ";
        }
        cout << " = " << s << ")";
    } else {
        cout << "False";
    }
    return 0;
}
