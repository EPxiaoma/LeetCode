#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> &heights) {
        stack<int> sta;
        sta.push(0);
        int result = 0;
        heights.insert(heights.begin(), 0);
        heights.insert(heights.end(), 0);

        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] >= heights[sta.top()]) {
                sta.push(i);
            } else {
                while (!sta.empty() && heights[i] < heights[sta.top()]) {
                    int mid = sta.top();
                    sta.pop();
                    if (!sta.empty()) {
                        int w = i - sta.top() - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
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
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = Solution().solve(heights);
    cout << result << endl;
}
