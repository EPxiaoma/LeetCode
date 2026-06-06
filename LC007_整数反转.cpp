#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(int x) {
        int result = 0;

        while (x) {
            int carry = x % 10;

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && carry > 7)) {
                return 0;
            }

            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && carry < -8)) {
                return 0;
            }


            result = result * 10 + carry;
            x = x / 10;
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int x = 123;
    int result = Solution().solve(x);
    cout << result << endl;
}
