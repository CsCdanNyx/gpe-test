#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10;
const int permutations[maxn] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};     // 0! to 9!, How many permutations(arrangements) of a number of circles.
double rad[maxn], x_axis[maxn];

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < n; ++i)
            cin >> rad[i];

        int cnt = permutations[n];
        double ans = 1e9;
        while (cnt--) {
            x_axis[0] = rad[0];
            double width = 2 * rad[0];

            for (int i = 1; i < n; ++i) {
                x_axis[i] = rad[i];

                for (int j = 0; j < i; ++j) 
                    x_axis[i] = max(x_axis[i], x_axis[j] + 2 * sqrt(rad[i] * rad[j]));     // sqrt((R+r)^2 - (R-r)^2) = 2 * sqrt(R * r)
            
                width = max(width, x_axis[i] + rad[i]);
            }

            ans = min(ans, width);
            next_permutation(rad, rad + n);     // Generate next Permutation(arrangement) of radius list.
        }

        cout.precision(3);
        cout << fixed << ans << endl;
    }
    return 0;
}
