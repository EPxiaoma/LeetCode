#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    string solve(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        vector<int> fact(n, 1);
        for (int i = 1; i < n; i++) {
            fact[i] = fact[i - 1] * i;
        }

        k--;
        string result;
        for (int i = n - 1; i >= 0; i--) {
            int index = k / fact[i];
            result += nums[index] + '0';
            nums.erase(nums.begin() + index);
            k %= fact[i];
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 3;
    int k = 3;
    string result = Solution().solve(n, k);
    cout << result << endl;
}
