#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <map>
#include <sstream>
using namespace std;

int m, n = 0;

char grid[105][105];
bool checked[105][105];

// For searching in all 8 directions for a cell
int dx[8] = { 0,  0, 1, -1, 1, -1, -1,  1};
int dy[8] = { 1, -1, 0,  0, 1, -1,  1, -1};

void dfs(int x, int y){
    if (x < 0 || x > m || y < 0 || y > n)
        return;

    if( grid[x][y] != '@' )
        return;
    
    if (checked[x][y])
        return;

    checked[x][y] = true;
    for(int i = 0; i < 8; i++){
        dfs(x + dx[i], y + dy[i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    while( cin >> m >> n ){
        if( m == 0 && n == 0 )
            break;

        memset(grid, '*', sizeof(grid));
        memset(checked, false, sizeof(checked));

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                cin >> grid[i][j];

        int ans = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                
                if( grid[i][j] == '@' ){
                    if( checked[i][j] == false ){
                        dfs(i, j);
                        ans++;
                    }
                }
                
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
