#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    // unsigned long long sum = 0;
    // for (int n = 0, k = n; n <= 400; n++, k=n%10, sum+=pow(k, k))
    // {
    //     // cout << sum << ":" << sum%10 << " ";
    //     cout << sum%10 << " ";
    //     sum %= 1000;
    //     if (n%20 == 0)
    //         cout << endl;
    // }

    for (int i = 0; i <= 20; i++)
    {
        ll result = i;
        for (int j = 1; j < i; j++)
        {
            result = (result * i) % 100;
        }
        
        // cout << result%10 << " ";
        // if (i%20 == 0)
        //     cout << endl;
    }
    
    int powder[20] = {1, 4, 7, 6, 5, 6, 3, 6, 9, 0, 1, 6, 3, 6, 5, 6, 7, 4, 9, 0};

    int sum = 0;

    for (int i = 0; i < 400; i++)
    {
        sum += powder[i%20];
        cout << sum%10 << " ";
        if ((i+1)%20 == 0)
            cout << endl;
    }
    
    
    // for (int n = 0, k = 0; n <= 20; n++, k=(k+1)%10, sum+=pow(k, k))
    // {
    //     // cout << sum << ":" << sum%10 << " ";
    //     cout << sum%10 << " ";
    //     sum %= 1000;
    //     if (n%20 == 0)
    //         cout << endl;
    // }

    return 0;
}