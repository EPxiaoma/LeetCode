#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;

    void backtracking(vector<int> nums, int startIndex) {
        result.push_back(path);

        for (int i = startIndex; i < nums.size(); i++) {
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int> > solve(vector<int> nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int> > result = Solution().solve(nums);

    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << '[';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ',';
            }
        }
        cout << ']';
        if (i < result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
