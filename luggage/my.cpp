#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int tests;
    cin >> tests;
    cin.ignore();

    stringstream ss("");
    string line;

    while (tests--)
    {
        getline(cin, line);
        ss << line;

        vector<int> suitcases;

        int n, sum = 0;
        while (ss >> n)
        {
            suitcases.push_back(n);
            sum += n;
        }

        ss.clear();
        ss.str("");

        if (sum % 2) {
            cout << "NO" << endl;
            continue;
        }

        sort(suitcases.begin(), suitcases.end());

        int mid = sum/2+5;
        bool loadable[mid] = {false};
        loadable[0] = true;

        for (size_t i = 0; i < suitcases.size(); i++)
            if (suitcases[i] < mid)
                for (int j = suitcases[i]; j < mid; j++)
                    if (loadable[j - suitcases[i]])
                        loadable[j] = true;

        
        
        // bool loadable[sum+5] = {false};
        // loadable[0] = true;

        // for (size_t i = 0; i < suitcases.size(); i++)
        // {
        //     for (int j = suitcases[i]; j < sum; j++)
        //     {
        //         if (loadable[j - suitcases[i]])
        //             loadable[j] = true;
        //     }
        // }

        
        if (loadable[sum/2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    

    


    return 0;
}