#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(int n) {
        int count = 1 << n;
        vector<int> result(count, 0);

        for (int i = 0; i < count; i++) {
            result[i] = i ^ (i >> 1);
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int n = 2;
    vector<int> result = Solution().solve(n);

    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
