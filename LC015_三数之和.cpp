#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<int> > solve(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (sum > 0) {
                    right--;
                } else {
                    left++;
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
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int> > result = Solution().solve(nums);

    cout << "[";
    for (auto &num: result) {
        cout << "[";
        for (int i = 0; i < num.size() - 1; i++) {
            cout << num[i] << ",";
        }
        cout << num[num.size() - 1];
        cout << "]";
    }
    cout << "]";
}
