#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    void solve(vector<int>& nums) {
        int left = 0;
        int cur = 0;
        int right = nums.size() - 1;
        while (cur <= right) {
            if (nums[cur] == 0) {
                swap(nums[left], nums[cur]);
                left++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[right]);
                right--;
            } else {
                cur++;
            }
        }
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution().solve(nums);
    cout << '[';
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
