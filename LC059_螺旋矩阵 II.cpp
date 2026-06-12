#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<int> > solve(int n) {
        vector<vector<int> > result(n, vector<int>(n, 0));
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        int count = 1;

        while (true) {
            for (int col = left; col <= right; col++) {
                result[up][col] = count++;
            }
            up++;
            if (up > down) {
                break;
            }

            for (int row = up; row <= down; row++) {
                result[row][right] = count++;
            }
            right--;
            if (right < left) {
                break;
            }

            for (int col = right; col >= left; col--) {
                result[down][col] = count++;
            }
            down--;
            if (down < up) {
                break;
            }

            for (int row = down; row >= up; row--) {
                result[row][left] = count++;
            }
            left++;
            if (left > right) {
                break;
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 3;
    vector<vector<int> > result = Solution().solve(n);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << '[';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ',';
            }
        }
        cout << ']';
        if (i < result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
