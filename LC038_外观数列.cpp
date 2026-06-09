#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    string solve(int n) {
        string result = "1";

        for (int i = 2; i <= n; i++) {
            int count = 1;
            string cur;
            for (int j = 1; j <= result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    cur += to_string(count) + result[j - 1];
                    count = 1;
                }
            }

            result = cur;
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 4;
    string result = Solution().solve(n);
    cout << result << endl;
}
