#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    double solve(vector<int> &nums1, vector<int> &nums2) {
        if (nums2.size() < nums1.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = -1;
        int right = m;

        while (left + 1 < right) {
            // i + 1 + j + 1 = (m + n + 1) / 2
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i - 2;

            if (nums1[i] <= nums2[j + 1]) {
                left = i;
            } else {
                right = i;
            }
        }

        int i = left;
        int j = (m + n + 1) / 2 - i - 2;

        int ai = i == -1 ? INT_MIN : nums1[i];
        int ai1 = i + 1 == m ? INT_MAX : nums1[i + 1];
        int bj = j == -1 ? INT_MIN : nums2[j];
        int bj1 = j + 1 == n ? INT_MAX : nums2[j + 1];

        int leftMax = max(ai, bj);
        int rightMin = min(ai1, bj1);

        return (m + n) % 2 == 0 ? (leftMax + rightMin) / 2.0 : leftMax;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double result = Solution().solve(nums1, nums2);
    cout << result << endl;
}
