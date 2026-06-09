#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool isValid(vector<vector<char> > &board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) {
                return false;
            }
        }

        for (int j = 0; j < 9; j++) {
            if (board[row][j] == val) {
                return false;
            }
        }

        int boxi = (row / 3) * 3;
        int boxj = (col / 3) * 3;

        for (int i = boxi; i < boxi + 3; i++) {
            for (int j = boxj; j < boxj + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }

        return true;
    }

    bool backtracking(vector<vector<char> > &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            bool result = backtracking(board);
                            if (result) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solve(vector<vector<char> > &board) {
        backtracking(board);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<vector<char> > board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution().solve(board);

    cout << '[';
    for (int i = 0; i < 9; i++) {
        cout << '[';
        for (int j = 0; j < 9; j++) {
            cout << '"' << board[i][j] << '"';
            if (j < 8) cout << ',';
        }
        cout << ']';
        if (i < 8) cout << ',' << endl;
    }
    cout << ']' << endl;
}
