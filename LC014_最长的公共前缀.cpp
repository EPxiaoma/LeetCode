#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    string solve(vector<string> &strs) {
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c || i >= strs[j].size()) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = Solution().solve(strs);
    cout << result << endl;
}
