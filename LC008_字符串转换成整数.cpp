#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        int result = 0;
        int index = 0;
        for (index; index < s.size(); index++) {
            if (s[index] != ' ') {
                break;
            }
        }

        int sign = 1;
        if (index < s.size() && s[index] == '-') {
            sign = -1;
            index++;
        } else if (index < s.size() && s[index] == '+') {
            index++;
        }

        for (index; index < s.size(); index++) {
            int num = s[index] - '0';

            if (num < 0 || num > 9) {
                break;
            }

            if (result > INT_MAX / 10 || result == INT_MAX / 10 && num > 7) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }

            result = result * 10 + num;

        }

        return sign * result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "42";
    int result = Solution().solve(s);
    cout << result << endl;
}
