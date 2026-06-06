#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    string solve(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);
        int reverse = -1;
        int row = 0;

        for (char c: s) {
            rows[row].push_back(c);
            if (row == 0 || row == numRows - 1) {
                reverse *= -1;
            }
            row += reverse;
        }

        string result;
        for (string s: rows) {
            result += s;
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = Solution().solve(s, numRows);
    cout << result << endl;
}
