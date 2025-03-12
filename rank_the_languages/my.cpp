#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<char>> lang_map(21, vector<char>(21, 0));
vector<int> lang_count(26, 0); 

int dx[4] = { 0,  0, -1, 1 };
int dy[4] = { 1, -1,  0, 0 };

int h = 0;
int w = 0;

void dfs(int row, int col, char c) {
    if (row < 0 || row >= h || col < 0 || col >= w)
        return;
    
    if (lang_map[row][col] != c)
        return;
    
    lang_map[row][col] = 0;
    
    for (size_t i = 0; i < 4; i++)
        dfs(row+dx[i], col+dy[i], c);

    return;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int cases;
    int world = 0;
    cin >> cases;
    while (cases--)
    {
        world++;

        fill(lang_map.begin(), lang_map.end(), vector<char>(21, 0));
        fill(lang_count.begin(), lang_count.end(), 0);

        cin >> h >> w;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> lang_map[i][j];
            
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (lang_map[i][j]) {
                    lang_count[lang_map[i][j]-'a']++;
                    dfs(i, j, lang_map[i][j]);
                }
            }
        }

        cout << "World #" << world << endl;


        vector<pair<char, int>> result;
        for (size_t i = 0; i < 26; i++) {
            if (lang_count[i] > 0) {
                result.push_back({char(i + 'a'), lang_count[i]});
            }
        }

        sort(result.begin(), result.end(), [](pair<char, int> a, pair<char, int> b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });

        for (auto &p : result)
            cout << p.first << ": " << p.second << endl;

    }

    return 0;
}