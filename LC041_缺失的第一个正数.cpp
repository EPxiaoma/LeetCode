#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != j + 1) {
                return j + 1;
            }
        }

        return nums.size() + 1;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {1, 2, 0};
    int result = Solution().solve(nums);
    cout << result << endl;
}
