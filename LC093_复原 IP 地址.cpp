#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<string> result;
    string path;

    bool isValid(string s, int left, int right) {
        if (left > right) {
            return false;
        }

        if (s[left] == '0' && left != right) {
            return false;
        }

        int sum = 0;
        for (int i = left; i <= right; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }

            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) {
                return false;
            }
        }

        return true;
    }

    void backtracking(string s, int startIndex, int point) {
        if (point == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(path + s.substr(startIndex));
            } else {
                return;
            }
        }

        for (int i = startIndex; i < s.size() && i < startIndex + 3; i++) {
            if (isValid(s, startIndex, i)) {
                string str = s.substr(startIndex, i - startIndex + 1);
                int size = str.size() + 1;
                path += str;
                path += '.';
                point++;
                backtracking(s, i + 1, point);
                point--;
                while (size--) {
                    path.pop_back();
                }
            } else {
                break;
            }
        }
    }

    vector<string> solve(string s) {
        backtracking(s, 0, 0);
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string s = "25525511135";
    vector<string> result = Solution().solve(s);

    cout << '[';

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ',';
        }
    }

    cout << ']';
}
