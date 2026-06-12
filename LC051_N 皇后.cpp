#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<string> > result;

    bool isValid(int n, vector<string> board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void backtracking(int n, vector<string> board, int row) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isValid(n, board, row, col)) {
                board[row][col] = 'Q';
                backtracking(n, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string> > solve(int n) {
        vector<string> board(n, string(n, '.'));
        backtracking(n, board, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 4;
    vector<vector<string> > result = Solution().solve(n);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << '[';
        for (int j = 0; j < result[i].size(); j++) {
            cout << '"';
            cout << result[i][j];
            cout << '"';
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
