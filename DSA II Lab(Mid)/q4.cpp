#include <iostream>
using namespace std;

int main() {
    int n = 4;  // number of coin types
    int X = 63; // target amount

    // Coin denominations and their limited supply
    int coins[4] = {25, 10, 5, 1};      // coin values
    int supply[4] = {2, 5, 5, 10};      // how many coins of each type available

    int totalCoins = 0;   // total coins used
    int amount = X;       // remaining amount

    cout << "Coins used:\n";
    for (int i = 0; i < n; i++) {
        int use = amount / coins[i];       // max coins needed of this type
        if (use > supply[i]) {
            use = supply[i];               // can’t use more than available
        }
        amount -= use * coins[i];          // reduce remaining amount
        totalCoins += use;

        if (use > 0) {
            cout << "Coin " << coins[i] << " used " << use << " times\n";
        }
    }

    if (amount == 0) {
        cout << "Minimum coins needed = " << totalCoins << endl;
    } else {
        cout << "Not Possible" << endl;
    }

    return 0;
}
