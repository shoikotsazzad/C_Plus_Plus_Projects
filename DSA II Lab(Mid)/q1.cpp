#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
    int priority;
    float ratio; // value-to-weight ratio
};

// Function to swap two items (for sorting)
void swap(Item &a, Item &b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Function to sort items by ratio (descending), break ties with priority
void sortItems(Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(arr[j], arr[j + 1]);
            }
            else if (arr[j].ratio == arr[j + 1].ratio) {
                if (arr[j].priority < arr[j + 1].priority) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(Item arr[], int n, int W) {
    sortItems(arr, n);

    int currentWeight = 0;
    float totalValue = 0.0;

    cout << "\nSelected items:\n";
    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            // take full item
            currentWeight += arr[i].weight;
            totalValue += arr[i].value;
            cout << "Take full item " << i + 1 
                 << " (value=" << arr[i].value 
                 << ", weight=" << arr[i].weight 
                 << ", priority=" << arr[i].priority << ")\n";
        } else {
            // take fractional part
            int remain = W - currentWeight;
            float fraction = (float)remain / arr[i].weight;
            totalValue += arr[i].value * fraction;
            cout << "Take " << fraction * 100 << "% of item " << i + 1 
                 << " (value=" << arr[i].value 
                 << ", weight=" << arr[i].weight 
                 << ", priority=" << arr[i].priority << ")\n";
            break;
        }
    }
    return totalValue;
}

int main() {
    int n = 3;        
    int W = 50;       


    Item arr[3] = {
        {60, 10, 2, 0}, 
        {100, 20, 1, 0}, 
        {120, 30, 3, 0}
    };


    for (int i = 0; i < n; i++) {
        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    float maxValue = fractionalKnapsack(arr, n, W);
    cout << "\nMaximum total value in knapsack = " << maxValue << endl;

    return 0;
}
