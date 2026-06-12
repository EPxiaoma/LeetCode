#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(vector<int> &nums) {
        int end = 0;
        for (int i = 0; i <= end; i++) {
            end = max(end, nums[i] + i);
            if (i >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    bool result = Solution().solve(nums);
    cout << boolalpha << result << endl;
}
