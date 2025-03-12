#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// #define MAX 6005        // 20 times
#define MAX 30005        // 100 times

using namespace std;

int main() {


    // $100, $50, $20, $10, and $5 notes and $2, $1, 50c, 20c, 10c and 5c 
    // 2000, 1000, 400, 200, and 100 notes and 40, 20, 10, 4, 2 and 1 

    // vector<int> coins = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};  // 20 times
    vector<int> coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};  // 100 times

    vector<long long> ways(MAX, 0);

    ways[0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = coins[i]; j < MAX; j++) {
            if (j - coins[i] >= 0)
                ways[j] += ways[j - coins[i]];
        }
    }



    int cost = 0;
    int num, deci = 0;
    char point;

    while (cin >> num >> point >> deci) {

        if (num == 0 && deci == 0)
            break;

        // cost = (num * 100 + deci)*20/100;   // 20 times
        cost = num * 100 + deci;         // 100 times

        cout << setw(3) << setfill(' ') << num << point << setw(2) << setfill('0') << deci << setw(17) << setfill(' ') << ways[cost] << endl;
        

    }


    return 0;
}