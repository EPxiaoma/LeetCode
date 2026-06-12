#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int result = 0;
    unordered_set<int> cols;
    unordered_set<int> leftUp;
    unordered_set<int> rightUp;

    void backtracking(int n, int row) {
        if (row == n) {
            result++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() || leftUp.find(col + row) != leftUp.end() || rightUp.find(row - col) !=
                rightUp.end()) {
                continue;
            }

            cols.insert(col);
            leftUp.insert(row + col);
            rightUp.insert(row - col);
            backtracking(n, row + 1);
            cols.erase(col);
            leftUp.erase(row + col);
            rightUp.erase(row - col);
        }
    }

    int solve(int n) {
        backtracking(n, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 4;
    int result = Solution().solve(n);
    cout << result << endl;
}
