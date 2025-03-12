#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int regions = 0;

    while (cin >> regions && regions) {

        for (int step = 1; step < regions; step++) {
            int win_index = 0;
            for (int remains = 2; remains < regions; remains++) {
                win_index = (win_index + step) % remains;
            }
            
            if (win_index == 11) {
                cout << step << endl;
                break;
            }
        }

        

    }


    return 0;
}