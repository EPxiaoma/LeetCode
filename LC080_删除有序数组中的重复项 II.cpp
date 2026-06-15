#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    int solve(vector<int> &nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int left = 2;
        int right = 2;
        while (right < nums.size()) {
            if (nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
            right++;
        }

        return left;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int result = Solution().solve(nums);
    cout << result << endl;
}
