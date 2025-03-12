#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    int n;
    while(cin >> n){
        vector<int> nums;
        int tmp;
        for(int i=0; i < n; i++) {
            cin >> tmp;
            nums.push_back(tmp);
        }

        sort(nums.begin(), nums.end());

        int mini, maxi = 0;
        int cnt = 0;

        if (n%2)
        {
            mini = nums[n/2];
            maxi =  nums[n/2];
            cnt = count(nums.begin(), nums.end(), mini);
        }
        else
        {
            mini = nums[n/2-1];
            maxi =  nums[n/2];
            cnt = count(nums.begin(), nums.end(), mini) + count(nums.begin(), nums.end(), maxi);
        }

        cout << mini << " " << cnt << " " << maxi-mini+1 << endl;

    }


    return 0;
}