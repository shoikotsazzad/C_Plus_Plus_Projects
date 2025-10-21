#include <iostream>
using namespace std;

int nums[10];
int n, target;
int combo[50];

void findCombinations(int index, int sum, int start) {
    if (sum == target) {
        cout << "[";
        for (int i = 0; i < index; i++) {
            cout << combo[i];
            if (i < index - 1) cout << ", ";
        }
        cout << "]" << endl;
        return;
    }

    if (sum > target)
        return;

    for (int i = start; i < n; i++) {
        combo[index] = nums[i];
        findCombinations(index + 1, sum + nums[i], i);
    }
}

int main() {
    int arr[] = {2, 3, 5};
    n = 3;
    target = 8;

    for (int i = 0; i < n; i++)
        nums[i] = arr[i];

    cout << "[" << endl;
    findCombinations(0, 0, 0);
    cout << "]";
}