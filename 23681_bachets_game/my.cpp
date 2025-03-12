#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int total, n;
    while(cin >> total >> n) {
        vector<int> stones(n);
    
        for(int i=0; i < n; i++)
            cin >> stones[i];
        
        sort(stones.begin(), stones.end());

        vector<bool> stan_win(total+5, false);

        for (int i = 1; i <= total; i++) {
            for (int j = 0; j < n; j++) {
                if ((i - stones[j] >= 0) && !stan_win[i - stones[j]])
                    stan_win[i] = true;
                if (stan_win[total])
                    break;
            }
        }


        if (stan_win[total])
            cout << "Stan wins" << endl;
        else
            cout << "Ollie wins" << endl;

    }




}