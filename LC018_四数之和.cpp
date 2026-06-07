#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<int> > solve(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;

        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] > 0 && target > 0 && nums[k] > target) {
                break;
            }

            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++) {
                if (i > k && nums[k] + nums[i] > 0 && target > 0 && nums[k] + nums[i] > target) {
                    break;
                }

                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    long sum = (long) nums[k] + nums[i] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }

                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (sum > target) {
                        right--;
                    } else {
                        left++;
                    }
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
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int> > result = Solution().solve(nums, target);

    cout << '[';
    for (auto &nums: result) {
        cout << '[';
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << ',';
        }
        cout << nums[nums.size() - 1];
        cout << ']';
    }
    cout << ']';
}
