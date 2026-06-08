#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<string> result;
    string path;

    void backtracking(int n, int left, int right) {
        if (right == n) {
            result.push_back(path);
            return;
        }

        if (left < n) {
            path.push_back('(');
            backtracking(n, left + 1, right);
            path.pop_back();
        }

        if (right < left) {
            path.push_back(')');
            backtracking(n, left, right + 1);
            path.pop_back();
        }
    }

    vector<string> solve(int n) {
        backtracking(n, 0, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 3;
    vector<string> result = Solution().solve(n);

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
