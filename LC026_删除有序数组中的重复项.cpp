#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> nums) {
        int left = 0;
        for (int right = 1; right < nums.size(); right++) {
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
        }

        return left + 1;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {1, 1, 2};
    int result = Solution().solve(nums);
    cout << result;
}
