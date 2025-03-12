#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);


    int cnt, jds = 0;
    cin >> cnt >> jds;
    map<string, long long> sal_dic;

    for (int i = 0; i < cnt; i++)
    {
        string tmp;
        long long money;
        cin >> tmp >> money;
        sal_dic[tmp] = money;
    }
    
    string jd_word;
    long long pay = 0;
    while (jds && cin >> jd_word)
    {
        if (jd_word == ".")
        {
            jds--;
            cout << pay << endl;
            pay = 0; 
            continue;
        }

        if (sal_dic.count(jd_word))
            pay += sal_dic[jd_word];
        
    }
    
    return 0;
}