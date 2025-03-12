#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t = 0;
    int n = 1;
    int w = 2;
    int e = 3;
    int s = 4;
    int b = 5;

    int num = 0;


    while (cin >> num && num) {

                //    t, n, w, e, s, b
        int dice[6] = {1, 2, 3, 4, 5, 6};

        while (num--)
        {
            string cmd;
            cin >> cmd;

            if (cmd == "north")
            {
                int tmp = dice[n];
                dice[n] = dice[t];
                dice[t] = dice[s];
                dice[s] = dice[b];
                dice[b] = tmp;
            }
            else if (cmd == "south")
            {
                int tmp = dice[b];
                dice[b] = dice[s];
                dice[s] = dice[t];
                dice[t] = dice[n];
                dice[n] = tmp;
            }
            else if (cmd == "east")
            {
                int tmp = dice[t];
                dice[t] = dice[w];
                dice[w] = dice[b];
                dice[b] = dice[e];
                dice[e] = tmp;
            }
            else if (cmd == "west")
            {
                int tmp = dice[e];
                dice[e] = dice[b];
                dice[b] = dice[w];
                dice[w] = dice[t];
                dice[t] = tmp;
            }
        }

        cout << dice[t] << endl;

    }


    return 0;
}