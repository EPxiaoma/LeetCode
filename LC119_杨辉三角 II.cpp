#include <bits/stdc++.h>
using namespace std;

// =====================================================================
// 链表
// =====================================================================

// 链表数据结构
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {
    }

    ListNode(int x) : val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

// 从 vector 构建链表
ListNode *buildList(const vector<int> &nums) {
    ListNode *dummy = new ListNode();
    ListNode *cur = dummy;
    for (int v: nums) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return dummy->next;
}

// 打印链表
void printList(ListNode *head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if (head->next) cout << ",";
        head = head->next;
    }
    cout << "]" << endl;
}

// =====================================================================
// 二叉树
// =====================================================================

// 二叉树数据结构
struct TreeNode {
    int val;
    TreeNode *left, *right, *next;

    TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {
    }

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r), next(nullptr) {
    }
};

// 从 vector 构建二叉树
TreeNode *buildTree(const vector<int> &nums) {
    if (nums.empty() || nums[0] == -1) return nullptr;
    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int) nums.size()) {
        TreeNode *node = q.front();
        q.pop();
        if (nums[i] != -1) {
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        if (i < (int) nums.size() && nums[i] != -1) {
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// 打印二叉树
string printTree(TreeNode *root) {
    if (!root) return "[]";
    queue<TreeNode *> q;
    q.push(root);
    vector<string> res;
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node) {
            res.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        } else { res.push_back("null"); }
    }
    while (!res.empty() && res.back() == "null") res.pop_back();
    string s = "[";
    for (int i = 0; i < (int) res.size(); i++) {
        if (i) s += ',';
        s += res[i];
    }
    return s + "]";
}

// =====================================================================
// 核心代码
// =====================================================================
class Solution {
public:
    vector<int> solve(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i - 1; j >= 1; j--) {
                result[j] = result[j - 1] + result[j];
            }
        }
        return result;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    int rowIndex = 3;
    vector<int> result = Solution().solve(rowIndex);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ',';
        }
    }
    cout << ']';
}
