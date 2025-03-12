#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int start = 0;
    ll day = 0;
    while (cin >> start >> day)
    {
        ll ans = start;
        ll sum = 0;
        for (ans = start, sum = 0; sum < day; sum+=ans, ans++)
        {
            // cout << "ans: " << ans << ", sum: " << sum << endl;
            ;
        }
        
        cout << --ans << endl;
    }
    
    

    return 0;
}