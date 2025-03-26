#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

typedef long long ll;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

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
        
        cout << "input: " << line << endl;
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }

        if (sum%2 != 0) {
            cout << "No such subset" << endl;
            continue;
        }

        ll mid = sum/2;
        cout << "sum: " << sum << endl;


        

    }


    return 0;
}