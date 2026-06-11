#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> &nums) {
        int cur = 0;
        int end = 0;
        int result = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            cur = max(cur, i + nums[i]);

            if (end == i) {
                result++;
                end = cur;
                if (end >= nums.size() - 1) {
                    return result;
                }
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = Solution().solve(nums);
    cout << result << endl;
}
