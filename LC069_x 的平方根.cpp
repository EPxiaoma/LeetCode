#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    int solve(int x) {
        int left = 1;
        int right = x;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long mul = (long long) mid * mid;
            if (mul == x) {
                return mid;
            } else if (mul < x) {
                left = mid + 1;
                result = mid;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int x = 4;
    int result = Solution().solve(x);
    cout << result << endl;
}
