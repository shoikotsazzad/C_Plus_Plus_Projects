#include <iostream>
using namespace std;

int countWays(int arr[], int n, int target, int index, int currentSum) {
    if (index == n) {
        if (currentSum == target)
            return 1;
        else
            return 0;
    }

    int plusWay = countWays(arr, n, target, index + 1, currentSum + arr[index]);
    int minusWay = countWays(arr, n, target, index + 1, currentSum - arr[index]);

    return plusWay + minusWay;
}

int main() {
    int arr[] = {1, 1, 2, 3};
    int n = 4;
    int target = 1;

    int ways = countWays(arr, n, target, 0, 0);

    cout << ways << " (different ways to make sum = " << target << ")";

    return 0;
}
