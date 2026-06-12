#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(vector<vector<int> > matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int up = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        while (true) {
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[up][col]);
            }
            up++;
            if (up > down) {
                break;
            }

            for (int row = up; row <= down; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;
            if (right < left) {
                break;
            }

            for (int col = right; col >= left; col--) {
                result.push_back(matrix[down][col]);
            }
            down--;
            if (down < up) {
                break;
            }

            for (int row = down; row >= up; row--) {
                result.push_back(matrix[row][left]);
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
    vector<vector<int> > matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result = Solution().solve(matrix);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
