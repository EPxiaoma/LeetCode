#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(vector<vector<char> > &board) {
        vector<vector<bool> > rows(9, vector<bool>(9, false));
        vector<vector<bool> > cols(9, vector<bool>(9, false));
        vector<vector<bool> > boxes(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }

                char c = board[i][j] - '1';

                if (rows[i][c] == true) {
                    return false;
                } else {
                    rows[i][c] = true;
                }

                if (cols[j][c] == true) {
                    return false;
                } else {
                    cols[j][c] = true;
                }

                int box = (i / 3) * 3 + (j / 3);
                if (boxes[box][c] == true) {
                    return false;
                } else {
                    boxes[box][c] = true;
                }
            }
        }

        return true;
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
    bool result = Solution().solve(board);
    cout << boolalpha << result << endl;
}
