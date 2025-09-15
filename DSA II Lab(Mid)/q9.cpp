#include <iostream>
using namespace std;

struct Activity {
    int start;
    int end;
    int profit;
};

// Swap function for sorting
void swap(Activity &a, Activity &b) {
    Activity temp = a;
    a = b;
    b = temp;
}

// Sort activities by end time (ascending)
void sortActivities(Activity arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].end > arr[j+1].end) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main() {
    int N = 5;
    int K = 1; // minimum break time between activities

    // Example activities {start, end, profit}
    Activity arr[5] = {
        {1, 3, 50},
        {2, 5, 20},
        {4, 6, 70},
        {6, 7, 60},
        {5, 8, 30}
    };

    // Sort activities by end time
    sortActivities(arr, N);

    int lastEnd = -K; // initialize so first activity can be chosen
    int totalProfit = 0;

    cout << "Selected activities:\n";
    for (int i = 0; i < N; i++) {
        if (arr[i].start >= lastEnd + K) { // check break time constraint
            totalProfit += arr[i].profit;
            lastEnd = arr[i].end;
            cout << "Activity (" << arr[i].start << ", " << arr[i].end << ") profit=" << arr[i].profit << endl;
        }
    }

    cout << "Maximum total profit = " << totalProfit << endl;

    return 0;
}
