#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
    float ratio; // value-to-weight
};

// Swap function for sorting
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Sort items by ratio (descending)
void sortItems(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Fill one knapsack and return value gained
float fillKnapsack(Item arr[], int n, int &startIndex, int capacity) {
    int currentWeight = 0;
    float totalValue = 0.0;

    cout << "\nFilling knapsack (capacity = " << capacity << "):\n";
    for (int i = startIndex; i < n; i++) {
        if (currentWeight + arr[i].weight <= capacity) {
            // take full item
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
            cout << "Take full item " << i + 1
                 << " (value=" << arr[i].value
                 << ", weight=" << arr[i].weight << ")\n";
            startIndex++; // move to next item for next knapsack
        } else {
            // take fraction
            int remain = capacity - currentWeight;
            float fraction = (float)remain / arr[i].weight;
            totalValue += arr[i].value * fraction;
            cout << "Take " << fraction * 100 << "% of item " << i + 1
                 << " (value=" << arr[i].value
                 << ", weight=" << arr[i].weight << ")\n";
            startIndex++; // move past this item (can’t reuse)
            break;
        }
    }
    return totalValue;
}

int main() {
    int n = 7;      // number of items
    int W1 = 50;    // knapsack 1 capacity
    int W2 = 30;    // knapsack 2 capacity

    // Example items {value, weight}
    Item arr[7] = {
        {60, 10, 0},
        {100, 20, 0},
        {120, 30, 0},
        {80, 40, 0},
        {50, 25, 0},
        {30, 10, 0},
        {70, 15, 0}
    };

    // compute ratios
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    // sort items by ratio
    sortItems(arr, n);

    int startIndex = 0;
    float totalValue = 0.0;

    // Fill knapsack 1
    totalValue += fillKnapsack(arr, n, startIndex, W1);

    // Fill knapsack 2 with remaining items
    totalValue += fillKnapsack(arr, n, startIndex, W2);

    cout << "\nMaximum total value across both knapsacks = " << totalValue << endl;

    return 0;
}
