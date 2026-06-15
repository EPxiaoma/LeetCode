#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

    bool dfs(vector<vector<char> > &board, string word, int x, int y, int index) {
        if (index == word.size()) {
            return true;
        }

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || word[index] != board[x][y]) {
            return false;
        }

        int temp = board[x][y];
        board[x][y] = '#';

        for (int i = 0; i < 4; i++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];

            if (dfs(board, word, nextX, nextY, index + 1)) {
                return true;
            }
        }

        board[x][y] = temp;
        return false;
    }

    bool solve(vector<vector<char> > &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<vector<char> > board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    bool result = Solution().solve(board, word);
    cout << boolalpha << result << endl;
}
