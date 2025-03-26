#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin >> n){
        vector<int> num_seq(n,0);
        for(int i=0; i<n; i++)
            cin >> num_seq[i];

        vector<int> lis;
        vector<int> lds;

        lis.push_back(num_seq[0]);
        lds.push_back(num_seq[n-1]);

        vector<int> lis_tail(n,0);
        vector<int> lds_tail(n,0);
        lis_tail[0] = 1;
        lds_tail[n-1] = 1;
        int lis_cnt = 1;
        int lds_cnt = 1;

        for(int i=1; i<n; i++){
            if(num_seq[i] > lis.back()){
                lis.push_back(num_seq[i]);
                lis_tail[i] = ++lis_cnt;
            }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), num_seq[i]);
                *it = num_seq[i];
                lis_tail[i] = (it - lis.begin() + 1);
            }
        }

        for(int i=n-2; i>=0; i--){
            if(num_seq[i] > lds.back()){
                lds.push_back(num_seq[i]);
                lds_tail[i] = ++lds_cnt;
            }
            else{
                auto it = lower_bound(lds.begin(), lds.end(), num_seq[i]);
                *it = num_seq[i];
                lds_tail[i] = (it - lds.begin() + 1);
            }
        }
        
        int t = min(lis_cnt, lds_cnt);
        bool out = false;
        for (; t>0; t--) {
            for (int i=0; i<n; i++) {
                if (lis_tail[i] >= t && lds_tail[i] >= t) {
                    cout << 2*t-1 << '\n';
                    out = true;
                    break;
                }
            }
            if (out)
                break;
        }
    }

    return 0;
}