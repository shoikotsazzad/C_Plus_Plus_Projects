#include <iostream>
#include <climits>
using namespace std;

int main() {
    int coins[3] = {1, 3, 4};
    int n = 3;
    int amount = 6;

    // ---- Greedy Approach ----
    int greedyAmount = amount;
    int greedyCoins = 0;
    int greedyUsed[3] = {0};

    // coins in descending order
    int descCoins[3] = {4, 3, 1};
    for (int i = 0; i < n; i++) {
        while (greedyAmount >= descCoins[i]) {
            greedyAmount -= descCoins[i];
            greedyCoins++;
            greedyUsed[i]++;
        }
    }

    cout << "Greedy coins used: " << greedyCoins << " (";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < greedyUsed[i]; j++) cout << descCoins[i] << " ";
    }
    cout << ")\n";

    // ---- Optimal DP Approach ----
    int dp[amount + 1];
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1)
                    dp[i] = dp[i - coins[j]] + 1;
            }
        }
    }

    cout << "Optimal coins needed: " << dp[amount] << endl;

    return 0;
}
