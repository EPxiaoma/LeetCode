#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    void solve(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int len1 = m - 1;
        int len2 = n - 1;
        int len = m + n - 1;

        while (len1 >= 0 && len2 >= 0) {
            if (nums1[len1] >= nums2[len2]) {
                nums1[len] = nums1[len1];
                len1--;
            } else {
                nums1[len] = nums2[len2];
                len2--;
            }
            len--;
        }

        while (len2 >= 0) {
            nums1[len] = nums2[len2];
            len--;
            len2--;
        }
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    Solution().solve(nums1, m, nums2, n);

    cout << '[';
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i];
        if (i < nums1.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
