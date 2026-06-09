#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;

    void backtracking(vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int> > solve(vector<int> &candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int> > result = Solution().solve(candidates, target);
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
