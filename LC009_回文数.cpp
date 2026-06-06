#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    bool solve(int x) {
        string s = to_string(x);
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right]) {
                return false;
            } else {
                left++;
                right--;
            }
        }

        return true;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int x = 121;
    bool result = Solution().solve(x);
    cout << boolalpha << result << endl;
}
