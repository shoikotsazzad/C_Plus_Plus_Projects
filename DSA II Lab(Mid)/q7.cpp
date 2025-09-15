#include <iostream>
using namespace std;

int main() {
    int N = 5;

    // Example meetings: {start, end}
    int start[5] = {1, 2, 3, 3, 5};
    int end[5]   = {2, 3, 4, 5, 6};

    // Find max end time
    int maxTime = end[0];
    for (int i = 1; i < N; i++) {
        if (end[i] > maxTime) maxTime = end[i];
    }

    // Timeline array to count meetings at each time
    int timeline[100] = {0}; // assuming maxTime <= 100

    for (int i = 0; i < N; i++) {
        for (int t = start[i]; t < end[i]; t++) {
            timeline[t]++; // increase count for each time unit the meeting occupies
        }
    }

    // Find the maximum count in timeline
    int minRooms = 0;
    for (int t = 0; t <= maxTime; t++) {
        if (timeline[t] > minRooms) minRooms = timeline[t];
    }

    cout << "Minimum number of rooms required = " << minRooms << endl;

    return 0;
}
