#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;

    while (cin >> n && n)
    {
        vector<long long> nums(n, 0);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        
        bool finded = false;
        
        // long long a, b, c;
        long long d;
        long long maxd = -1;
        for (int i = 0; i < n-3; i++)
        {
            for (int j = i+1; j < n-2; j++)
            {
                for (int k = j+1; k < n-1; k++)
                {
                    if (i < j && j < k)
                    {
                        d = nums[i] + nums[j] + nums[k];
                        if(count(nums.begin(), nums.end(), d))
                        {
                            finded = true;
                            if(d > maxd)
                                maxd = d;
                        }
                    }
                    
                }
                
            }
        }
        
        if (finded)
            cout << maxd << endl;
        else
            cout << "no solution" << endl;


    }
    

    


    return 0;
}