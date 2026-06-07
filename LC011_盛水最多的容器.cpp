#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    int solve(vector<int> &height) {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right) {
            int w = right - left;
            int h = min(height[left], height[right]);
            result = max(result, h * w);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = Solution().solve(height);
    cout << result << endl;
}
