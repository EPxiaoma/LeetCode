#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(string s) {
        int left = 0;
        unordered_set<char> set;
        int result = 0;
        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            result = max(right - left + 1, result);
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "abcabcbb";
    int result = Solution().solve(s);
    cout << result << endl;
}
