#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int div(long a, long b) {
        if (a < b) {
            return 0;
        }

        long count = 1;
        long db = b;
        while (db + db <= a) {
            count *= 2;
            db *= 2;
        }

        return count + div(a - db, b);
    }

    int solve(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }

        if (divisor == 1) {
            return dividend;
        }

        if (divisor == -1) {
            if (dividend > INT_MAX) {
                return dividend * (-1);
            } else {
                return INT_MAX;
            }
        }

        long a = (long) dividend;
        long b = (long) divisor;

        long sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }

        return sign * div(abs(a), abs(b));
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int dividend = 10;
    int divisor = 3;
    int result = Solution().solve(dividend, divisor);
    cout << result << endl;
}
