#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        int endIndex = s.size() - 1;
        for (endIndex; endIndex >= 0; endIndex--) {
            if (s[endIndex] != ' ') {
                break;
            }
        }

        int startIndex = endIndex;
        for (startIndex; startIndex >= 0; startIndex--) {
            if (s[startIndex] == ' ') {
                break;
            }
        }

        return endIndex - startIndex;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "Hello World";
    int result = Solution().solve(s);
    cout << result << endl;
}
