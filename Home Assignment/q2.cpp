#include <iostream>
using namespace std;

bool findMinCoins(int coins[], int count[], int n, int A, int& minCoins, int usedCoins[]) {
    bool possible = false;
    minCoins = 9999;

    int totalComb = 1;
    for (int i = 0; i < n; i++)
        totalComb *= (count[i] + 1);

    for (int a = 0; a <= count[0]; a++) {
        for (int b = 0; b <= count[1]; b++) {
            for (int c = 0; c <= count[2]; c++) {
                int sum = a * coins[0] + b * coins[1] + c * coins[2];
                int total = a + b + c;
                if (sum == A) {
                    possible = true;
                    if (total < minCoins) {
                        minCoins = total;
                        usedCoins[0] = a;
                        usedCoins[1] = b;
                        usedCoins[2] = c;
                    }
                }
            }
        }
    }

    return possible;
}

int main() {
    int coins[3] = {1, 2, 5};
    int count[3] = {2, 1, 1};
    int n = 3;
    int A = 7;
    int minCoins;
    int usedCoins[3];

    if (findMinCoins(coins, count, n, A, minCoins, usedCoins)) {
        cout << "True (";
        bool first = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < usedCoins[i]; j++) {
                if (!first) cout << " + ";
                cout << coins[i];
                first = false;
            }
        }
        cout << ")\nminimal coin count = " << minCoins;
    } else {
        cout << "False";
    }

    return 0;
}
