#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int num = target - nums[i];
            if (map.find(num) != map.end()) {
                return {i, map[num]};
            } else {
                map[nums[i]] = i;
            }
        }

        return {};
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = Solution().solve(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}
