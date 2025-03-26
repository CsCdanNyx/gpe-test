#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll dp[250];
ll dfs(int i){
    if(i == s.size()) return 0;
    if(dp[i] != -1) return dp[i];

    ll res = 0, sum = 0;
    // enum split point
    for(int j = i; j < s.size(); ++j){
        sum = sum * 10 + s[j] - '0';
        if(sum > INT_MAX) break;
        res = max(res, sum + dfs(j+1));
    }
    return dp[i] = res;
}

void solve(){
    memset(dp, -1, sizeof dp);
    cin >> s;
    cout << dfs(0) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    // int n;
    // cin >> n;
    // while(n--)
    //     solve();

    string line;

    while (getline(cin, line) && line != ".") {

        string num_str = line.substr(1, line.size() - 2);

        istringstream iss(num_str);

        vector<ll> nums;

        ll tmp;
        ll sum = 0;

        while (iss >> tmp)
        {
            nums.push_back(tmp);
            sum += tmp;
        }
    }

}