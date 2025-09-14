#include <iostream>
using namespace std;

int main() {
    int n = 4;      // number of coin types
    int X = 63;     // target amount

    // Coin denominations (largest to smallest)
    int coins[4] = {25, 10, 5, 1};
    int totalTransactions = 0;
    int amount = X;

    cout << "Coins used:\n";

    for (int i = 0; i < n; i++) {
        int use = amount / coins[i];  // max coins we can use of this type
        amount -= use * coins[i];
        totalTransactions += use;     // each coin counts as 1 transaction
        totalTransactions += use;     // each coin has a fee of 1 transaction

        if (use > 0) {
            cout << "Coin " << coins[i] << " used " << use 
                 << " times (including fee: " << use << ")\n";
        }
    }

    if (amount == 0) {
        cout << "Total transactions (coins + fees) = " << totalTransactions << endl;
    } else {
        cout << "Not Possible" << endl;
    }

    return 0;
}
