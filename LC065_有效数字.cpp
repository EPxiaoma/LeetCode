#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    bool solve(string s) {
        int index = 0;
        if (s[index] == '-' || s[index] == '+') {
            index++;
        }

        bool has_dot = false;
        bool has_num = false;
        for (index; index < s.size() && (s[index] != 'e' && s[index] != 'E'); index++) {
            if (s[index] == '.') {
                if (has_dot) {
                    return false;
                }
                has_dot = true;
            } else if (s[index] < '0' || s[index] > '9') {
                return false;
            } else {
                has_num = true;
            }
        }

        if (has_num == false) {
            return false;
        }

        if (index < s.size() && (s[index] == 'e' || s[index] == 'E')) {
            index++;

            if (index < s.size() && (s[index] == '-' || s[index] == '+')) {
                index++;
            }

            bool has_num = false;
            while (index < s.size()) {
                if (s[index] < '0' || s[index] > '9') {
                    return false;
                } else {
                    has_num = true;
                }
                index++;
            }

            if (has_num == false) {
                return false;
            }
        }

        return index == s.size();
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "0";
    bool result = Solution().solve(s);
    cout << boolalpha << result << endl;
}
