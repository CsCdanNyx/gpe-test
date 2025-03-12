#include <iostream>
#include <set>

using namespace std;

#define MAXN 100200


// [解題方法]
// 模擬蜜蜂 Willi 的移動，根據兩個座標系的規律來生成座標。
// 規律是：數字組成的六邊形，每一邊的數字遞迴規律是一樣的。
// 如 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 9 這 12 個數字組成的六邊形，
// 左下邊由 9, 10, 11 組成，橫座標是依次減一，縱座標不變，對於其他邊也有類似的規律，
// 例外的是右下邊，由於只有 8, 9 兩個數，需要特殊處理組成該條邊的數字。
// 處理時的起始蜂房編號選擇 1, 2, 9, 22,…，其相鄰編號之差形成一個初始項為 1，差為 6 的等差數列。
// 由於起始處理蜂房編號的關係，需要適當放寬需要計算的蜂房座標數量，否則會有一部分蜂房編號因為循環的關係而得不到計算。



int offset[5][2] = { { -1, 0 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 0, 1 } };
pair<int, int> maja[MAXN + 2000];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    for (int i = 1, j = 1, k = 0; i < MAXN ; i += j, j += 6, k++) {

        maja[i] = make_pair(0, k);      // 從原點往下計算 1 -> (0,0), 2 -> (0,1), 9 -> (0,2), 22 -> (0,3), ...
        for (int m = 0; m < k; m++)
            maja[i - m] = make_pair(m, k - m);

        int current = i;
        for (int m = 0; m < 5; m++)
            for (int n = 0; n < k; n++) {

                int x = maja[current].first + offset[m][0];
                int y = maja[current].second + offset[m][1];
                maja[current + 1] = make_pair(x, y);
                current++;

            }
    }

    int willi;
    while (cin >> willi)
        cout << maja[willi].first << " " << maja[willi].second << endl;

    return 0;
}