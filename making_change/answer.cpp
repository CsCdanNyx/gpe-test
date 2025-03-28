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

int m[6] = {1,2,4,10,20,40};  // 5c, 10c, 20c, 50c, $1 and $2  *20
int num[6];
int change[3005];
int give[3005];
double n;
const int inf = 100000000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    memset(change, 0, sizeof(change));

    // shopkeeper greedy
    for(int j=1; j<3001; j++){
        int keeper_return = j;
        int cnt = 0;
        for(int i=5; i>=0; i--){
            cnt += (keeper_return / m[i]);
            keeper_return -= (m[i] * (keeper_return / m[i]));
            if(keeper_return == 0)
                break;
        }
        change[j] = cnt;
    }

    while(cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> n){
        if(num[0]+num[1]+num[2]+num[3]+num[4]+num[5] == 0)
            break;

        int x = (n+0.005) * 100.0;
        x /= 5;

        for(int i=0; i<3001; i++)
            give[i] = inf;

        // customer give
        give[0] = 0;
        int tot = 0;
        for(int i=0; i<6; i++){
            tot += num[i] * m[i];
            for(int j=1; j<=num[i]; j++){
                for(int k=tot; k>=m[i]*j; k--){
                    give[k] = min(give[k], give[k-m[i]*j]+j);
                }
            }
        }

        // min of customer give and give more + keeper change return
        int ans = give[x];
        for(int i=x+1; i<=100; i++)     // $5 *20
            ans = min(ans, give[i] + change[i-x]);

        cout << setw(3) << ans << '\n';
    }

    return 0;
}