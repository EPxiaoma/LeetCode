#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> getNext(string needle) {
        vector<int> next(needle.size(), 0);
        int j = 0;
        for (int i = 1; i < needle.size(); i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }

            if (needle[i] == needle[j]) {
                j++;
            }

            next[i] = j;
        }
        return next;
    }

    int solve(string haystack, string needle) {
        vector<int> next = getNext(needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j]) {
                j++;
            }

            if (j == needle.size()) {
                return i - j + 1;
            }
        }

        return -1;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    int result = Solution().solve(haystack, needle);
    cout << result << endl;
}
