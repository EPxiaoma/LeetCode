#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        int result = 0;
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else {
                sta.pop();
                if (!sta.empty()) {
                    result = max(result, i - sta.top());
                } else {
                    sta.push(i);
                }
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "(()";
    int result = Solution().solve(s);
    cout << result << endl;
}
