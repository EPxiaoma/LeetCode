#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        if (s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= s.size(); i++) {
            int oneNum = s[i - 1] - '0';
            if (oneNum != 0) {
                dp[i] += dp[i - 1];
            }

            int twoNum = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (twoNum >= 10 && twoNum <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.size()];
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "12";
    int result = Solution().solve(s);
    cout << result << endl;
}
