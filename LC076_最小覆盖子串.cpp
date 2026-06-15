#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    string solve(string s, string t) {
        unordered_map<char, int> target_map;
        for (auto &c: t) {
            target_map[c]++;
        }

        unordered_map<char, int> win_map;
        int left = 0;
        int right = 0;
        int count = 0;
        int min_len = INT_MAX;
        int startIndex = 0;
        while (right < s.size()) {
            char add_char = s[right];
            if (target_map.find(add_char) != target_map.end()) {
                win_map[add_char]++;
                if (win_map[add_char] == target_map[add_char]) {
                    count++;
                }
            }
            right++;

            while (count == target_map.size()) {
                if (min_len > right - left) {
                    min_len = right - left;
                    startIndex = left;
                }

                char del_char = s[left];
                if (target_map.find(del_char) != target_map.end()) {
                    if (win_map[del_char] == target_map[del_char]) {
                        count--;
                    }
                    win_map[del_char]--;
                }
                left++;
            }
        }


        return min_len == INT_MAX ? "" : s.substr(startIndex, min_len);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = Solution().solve(s, t);
    cout << result << endl;
}
