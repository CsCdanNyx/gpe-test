#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>

#define MAX 100006

using namespace std;


int dx[5] = { -1,  0,  1, 1, 0 };
int dy[5] = {  0, -1, -1, 0, 1 };

pair<int, int> maja[MAX];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int bot=1, inc=1, k=0; bot < MAX; bot+=inc, inc+=6, k++)
    {
        maja[bot] = make_pair(0, k);        // bottom
        
        for (int m = 0; m < k; m++)         // bottom right
            maja[bot-m] = make_pair(m, k-m);
        
        int num = bot;
        for (int i = 0; i < 5; i++)
        {
            for (int m = 0; m < k; m++)
            {
                maja[num+1] = make_pair(maja[num].first + dx[i], maja[num].second + dy[i]);
                num++;
            }
            
        }
        
    }
    

    int will;
    while (cin >> will)
        cout << maja[will].first << " " << maja[will].second << endl;
    
    
    
    return 0;
}