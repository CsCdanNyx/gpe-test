#include <iostream>
#include <vector>

using namespace std;


int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 0;
    cin >> cases;


    while (cases--)
    {
        int points_n = 0;
        cin >> points_n;
        vector<vector<int>> points(points_n);

        for (size_t i = 0; i < points_n; i++)
        {
            cin >> points[i][0] >> points[i][1];
        }
        
        vector<float> slopes;
        for (size_t i = 0; i < points_n; i++)
        {
            for (size_t j = i+1; j < points_n; j++)
            {
                if (points[i][0] == points[j][0])
                {
                    slopes.push_back(1000000);
                }
                else
                {
                    slopes.push_back((points[j][1] - points[i][1]) / (points[j][0] - points[i][0]));
                }
            }
        }

    }
    

    int m, n = 0;

    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;

        vector<vector<int>> grid(m, vector<int>(n, 0));

        

    }


    return 0;
}