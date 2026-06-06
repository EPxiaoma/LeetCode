#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int expand(string s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string solve(string s) {
        if (s.size() == 1) {
            return s;
        }

        string result = {};

        for (int i = 0; i < s.size(); i++) {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);

            int maxLen = max(len1, len2);
            if (maxLen > result.size()) {
                result = s.substr(i - (maxLen - 1) / 2, maxLen);
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "babad";
    string result = Solution().solve(s);
    cout << result << endl;
}
