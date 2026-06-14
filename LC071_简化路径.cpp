#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    string solve(string path) {
        stack<string> sta;
        int n = path.size();
        int left = 0;
        int right = 0;
        while (right < n) {
            if (path[left] == '/') {
                left++;
                right = left;
                continue;
            }

            while (right < n && path[right] != '/') {
                right++;
            }

            string s = path.substr(left, right - left);
            if (s == "..") {
                if (!sta.empty()) {
                    sta.pop();
                }
            } else if (s != ".") {
                sta.push(s);
            }

            left = right;
        }

        if (sta.empty()) {
            return "/";
        }

        string result;
        while (!sta.empty()) {
            result = "/" + sta.top() + result;
            sta.pop();
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string path = "/home/";
    string result = Solution().solve(path);
    cout << result << endl;
}
