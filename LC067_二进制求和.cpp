#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================

class Solution {
public:
    string solve(string a, string b) {
        int carry = 0;
        string result = "";
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
            }

            if (j >= 0) {
                sum += b[j] - '0';
            }

            result += to_string(sum % 2);
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string a = "11";
    string b = "1";
    string result = Solution().solve(a, b);
    cout << result << endl;
}
