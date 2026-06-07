#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        unordered_map<char, int> map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && map[s[i]] < map[s[i + 1]]) {
                result -= map[s[i]];
            } else {
                result += map[s[i]];
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "III";
    int result = Solution().solve(s);
    cout << result << endl;
}
