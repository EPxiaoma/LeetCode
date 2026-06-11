#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    void solve(vector<vector<int> > &matrix) {
        int n = matrix.size();
        if (n == 1) {
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution().solve(matrix);

    cout << '[';
    for (int i = 0; i < matrix.size(); i++) {
        cout << '[';
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) {
                cout << ',';
            }
        }
        cout << ']';
        if (i < matrix.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
