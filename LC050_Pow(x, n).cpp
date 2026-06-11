#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    double traversal(double x, long n) {
        if (n == 0) {
            return 1.0;
        }

        double result = traversal(x, n / 2);
        result *= result;
        if (n % 2 == 1) {
            result *= x;
        }

        return result;
    }

    double solve(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N *= (-1);
        }

        return pow(x, N);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    double x = 2.00000;
    int n = 10;
    double result = Solution().solve(x, n);
    cout << result << endl;
}
