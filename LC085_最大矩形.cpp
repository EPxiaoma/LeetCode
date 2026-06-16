#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int maxArea(vector<int> heights) {
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

    int solve(vector<vector<char> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int result = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            result = max(result, maxArea(heights));
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<vector<char> > matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int result = Solution().solve(matrix);
    cout << result << endl;
}
