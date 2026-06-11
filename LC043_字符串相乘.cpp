#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    string solve(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        vector<int> result(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
                result[i + j + 1] = mul % 10;
                result[i + j] += mul / 10;
            }
        }

        int index = 0;
        for (index; index < result.size(); index++) {
            if (result[index] != 0) {
                break;
            }
        }

        string s = "";
        for (index; index < result.size(); index++) {
            s += to_string(result[index]);
        }

        return s;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    string num1 = "2";
    string num2 = "3";
    string result = Solution().solve(num1, num2);
    cout << result << endl;
}
