#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(string s) {
        stack<char> sta;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sta.push(')');
            } else if (s[i] == '[') {
                sta.push(']');
            } else if (s[i] == '{') {
                sta.push('}');
            } else {
                if (sta.empty() || s[i] != sta.top()) {
                    return false;
                } else {
                    sta.pop();
                }
            }
        }

        return sta.empty();
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "()";
    bool result = Solution().solve(s);
    cout << boolalpha << result << endl;
}
