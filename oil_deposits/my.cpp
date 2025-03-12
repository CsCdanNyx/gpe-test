#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int m, n = 0;
vector<vector<char>> grid(105, vector<char>(105));

int dx[] = {1,  1,  0, -1, -1, -1,  0,  1};
int dy[] = {0,  1,  1,  1,  0, -1, -1, -1};

void dfs(int x, int y) {
    
    if (x < 0 || x > m || y < 0 || y > n)
        return;

    if (grid[x][y] != '@')
        return;

    grid[x][y] = '*';

    for (int i = 0; i < 8; i++)
        dfs(x + dx[i], y + dy[i]);

    return;
}



int main() {

    m = 0;
    n = 0;

    while (cin >> m >> n) {
        
        fill(grid.begin(), grid.end(), vector<char>(105, '*'));

        int count = 0;

        if (m == 0 && n == 0)
            break;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    dfs(i, j);
                    count++;
                }
            }
        }

        cout << count << endl;
    }


    return 0;
}