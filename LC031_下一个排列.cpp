#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(vector<int> &nums) {
        int i = nums.size() - 2;
        for (i; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }

        if (i >= 0) {
            for (int k = nums.size() - 1; k > i; k--) {
                if (nums[k] > nums[i]) {
                    swap(nums[k], nums[i]);
                    break;
                }
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> result = Solution().solve(nums);
    cout << '[';
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ',';
    }
    cout << nums[nums.size() - 1];
    cout << ']';
}
