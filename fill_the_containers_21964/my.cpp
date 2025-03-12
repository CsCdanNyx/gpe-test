#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int vsl_count = 0;
    long long con_count = 0;
    vector<long long>vsl_cap(105);

    while (cin >> vsl_count >> con_count) {

        long long sum = 0;

        for (int i = 0; i < vsl_count; i++) {
            cin >> vsl_cap[i];
            sum += vsl_cap[i];
        }


        long long low = 1;
        long long high = sum;
        long long mid = 0;
        long long best = high+1;

        while (low <= high) {

            mid = (high + low) / 2;

            long long current_con = 1;
            long long current_vol = 0;

            for (int i = 0; i < vsl_count; i++) {
                current_vol += vsl_cap[i];
                if (current_vol > mid) {
                    current_con++;
                    current_vol = vsl_cap[i];
                }
                else if (current_vol == mid) {
                    current_con++;
                    current_vol = 0;
                }

            }

            // if (current_vol) {
            //     current_con++;
            // }
            
            if (current_con == con_count) {
                best = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }

        }


        cout << best << endl;
        vsl_cap.clear();
        

    }


    return 0;
}