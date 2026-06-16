#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(string s1, string s2) {
        int m = s1.size();
        vector<vector<vector<bool> > > dp(m + 1, vector<vector<bool> >(m, vector<bool>(m, false)));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    dp[1][i][j] = true;
                }
            }
        }

        for (int len = 2; len <= m; len++) {
            for (int i = 0; i <= m - len; i++) {
                for (int j = 0; j <= m - len; j++) {
                    for (int k = 0; k <= len; k++) {
                        if (dp[k][i][j] && dp[len - k][i + k][j + k] ||
                            dp[k][i][j + len - k] && dp[len - k][i + k][j]) {
                            dp[len][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[m][0][0];
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s1 = "great";
    string s2 = "rgeat";
    bool result = Solution().solve(s1, s2);
    cout << boolalpha << result << endl;
}
