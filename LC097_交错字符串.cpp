#include <bits/stdc++.h>
using namespace std;
// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();


        if (m + n != s3.size()) {
            return false;
        }

        vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s3[i - 1]) {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int j = 1; j <= n; j++) {
            if (s2[j - 1] == s3[j - 1]) {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                bool first = false;
                bool second = false;

                if (s1[i - 1] == s3[i + j - 1]) {
                    first = dp[i - 1][j];
                }

                if (s2[j - 1] == s3[i + j - 1]) {
                    second = dp[i][j - 1];
                }

                dp[i][j] =  first || second;
            }
        }

        return dp[m][n];
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 3;
    int result = Solution().solve(n);
    cout << result << endl;
}
