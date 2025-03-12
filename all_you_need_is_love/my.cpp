#include <iostream>
#include <vector>
#include <string>

using namespace std;



long long gcd (long long a, long long b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tests = 0;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        long long a = 0, b = 0;
        string x, y;

        cin >> x >> y;

        long long base = 1;
        for (int i = x.size()-1; i >= 0; i--)
        {
            a += (x[i] - '0') * base; 
            base *= 2;
        }
        
        base = 1;
        for (int i = y.size()-1; i >= 0; i--)
        {
            b += (y[i] - '0') * base; 
            base *= 2;
        }

        long long L = gcd(a, b);

        // cout << "a= " << a << " , b= " << b << " , L= " << L << endl;

        cout << "Pair #" << test+1 << ": ";

        if(L==1)
            cout << "Love is not all you need!" << endl;
        else
            cout << "All you need is love!" << endl;
    }
    


    return 0;
}