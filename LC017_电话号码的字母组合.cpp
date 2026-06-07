#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<string> result;
    string path;

    unordered_map<int, string> map = {
        {0, ""},
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };

    void backtracking(string digits, int index) {
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string s = map[digit];

        for (int i = 0; i < s.size(); i++) {
            path.push_back(s[i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }

    vector<string> sove(string digits) {
        backtracking(digits, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string digits = "23";
    vector<string> result = Solution().sove(digits);

    cout << '[';
    for (auto &s: result) {
        cout << '"';
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
        }
        cout << '"';
    }
    cout << ']';
}
