#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> &height) {
        stack<int> sta;
        sta.push(0);
        int result = 0;

        for (int i = 1; i < height.size(); i++) {
            if (height[i] <= height[sta.top()]) {
                sta.push(i);
            } else {
                while (!sta.empty() && height[i] > height[sta.top()]) {
                    int mid = sta.top();
                    sta.pop();
                    if (!sta.empty()) {
                        int w = i - sta.top() - 1;
                        int h = min(height[i], height[sta.top()]) - height[mid];
                        result += w * h;
                    }
                }
                sta.push(i);
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = Solution().solve(height);
    cout << result << endl;
}
