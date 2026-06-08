#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(string s, vector<string> words) {
        int words_size = words.size();
        int word_size = words[0].size();
        int win_size = word_size * words_size;

        unordered_map<string, int> target_map;
        for (int i = 0; i < words_size; i++) {
            target_map[words[i]]++;
        }

        vector<int> result;

        for (int start = 0; start < word_size; start++) {
            unordered_map<string, int> cur_map;
            int over = 0;
            for (int right = start + word_size; right <= s.size(); right += word_size) {
                string in_word = s.substr(right - word_size, word_size);
                if (cur_map[in_word] == target_map[in_word]) {
                    over++;
                }
                cur_map[in_word]++;

                int left = right - win_size;
                if (left < 0) {
                    continue;
                }

                if (over == 0) {
                    result.push_back(left);
                }

                string out_word = s.substr(left, word_size);
                cur_map[out_word]--;
                if (cur_map[out_word] == target_map[out_word]) {
                    over--;
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
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = Solution().solve(s, words);
    cout << '[';
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ',';
    }
    cout << result[result.size() - 1];
    cout << ']';
}
