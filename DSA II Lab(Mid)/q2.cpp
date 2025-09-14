#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
    float ratio; // weight-to-value ratio
};

// Swap function for sorting
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Sort by weight/value ratio (ascending)
void sortItems(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio > arr[j + 1].ratio) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to minimize weight for at least value V
float minWeightForValue(Item arr[], int n, int V) {
    sortItems(arr, n);

    int currentValue = 0;
    float totalWeight = 0.0;

    cout << "\nSelected items:\n";
    for (int i = 0; i < n; i++) {
        if (currentValue + arr[i].value <= V) {
            // take full item
            currentValue += arr[i].value;
            totalWeight += arr[i].weight;
            cout << "Take full item " << i + 1
                 << " (value=" << arr[i].value
                 << ", weight=" << arr[i].weight << ")\n";
        } else {
            // take fraction of item
            int remain = V - currentValue;
            float fraction = (float)remain / arr[i].value;
            totalWeight += arr[i].weight * fraction;
            cout << "Take " << fraction * 100 << "% of item " << i + 1
                 << " (value=" << arr[i].value
                 << ", weight=" << arr[i].weight << ")\n";
            break;
        }
    }
    return totalWeight;
}

int main() {
    int n = 7;    // number of items
    int V = 200;  // target value

    // Example items: {value, weight}
    Item arr[7] = {
        {60, 20, 0},
        {100, 50, 0},
        {120, 30, 0},
        {80, 40, 0},
        {30, 10, 0},
        {50, 25, 0}
    };

    // calculate weight/value ratio
    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].weight / arr[i].value;
    }

    float minWeight = minWeightForValue(arr, n, V);
    cout << "\nMinimum weight required to get at least value " << V << " = " << minWeight << endl;

    return 0;
}
