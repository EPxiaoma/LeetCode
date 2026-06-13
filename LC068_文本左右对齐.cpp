#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    vector<string> solve(vector<string> words, int maxWidth) {
        vector<string> result;
        int left = 0;
        while (left < words.size()) {
            int right = left + 1;
            int lineLen = words[left].size();
            while (right < words.size() && words[right].size() + lineLen + 1 <= maxWidth) {
                lineLen += words[right].size() + 1;
                right++;
            }

            int wordSize = right - left;
            int totalChars = 0;
            for (int k = left; k < right; k++) {
                totalChars += words[k].size();
            }

            string line = "";

            if (right == words.size() || wordSize == 1) {
                for (int k = left; k < right; k++) {
                    line += words[k];
                    if (k != right - 1) {
                        line += ' ';
                    }
                }

                int space = maxWidth - line.size();
                while (space--) {
                    line += ' ';
                }
            } else {
                int totalSpaces = maxWidth - totalChars;
                int gaps = wordSize - 1;
                int spacesPregap = totalSpaces / gaps;
                int extraSpace = totalSpaces % gaps;

                for (int k = left; k < right; k++) {
                    line += words[k];
                    if (k < right - 1) {
                        int space = spacesPregap + (k - left < extraSpace ? 1 : 0);
                        while (space--) {
                            line += ' ';
                        }
                    }
                }
            }

            result.push_back(line);
            left = right;
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = Solution().solve(words, maxWidth);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << '"';
        cout << result[i];
        cout << '"';
        if (i != result.size() - 1) {
            cout << ',' << endl;
        }
    }
    cout << ']';
}
