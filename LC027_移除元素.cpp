#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> nums, int val) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {3, 2, 2, 3};
    int result = Solution().solve(nums, 3);
    cout << result;
}
