#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<vector<string> > solve(vector<string> &strs) {
        unordered_map<string, vector<string> > map;

        for (int i = 0; i < strs.size(); i++) {
            string sortStr = strs[i];
            sort(sortStr.begin(), sortStr.end());
            map[sortStr].push_back(strs[i]);
        }

        vector<vector<string> > result;
        for (auto &s: map) {
            result.push_back(s.second);
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    vector<vector<string> > result = Solution().solve(strs);

    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << '[';
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j + 1 < result[i].size()) cout << ",";
        }
        cout << ']';
        if (i < result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
