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
    TreeNode *solve(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            int size = que.size();
            TreeNode *pre;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = que.front();
                que.pop();

                if (i == 0) {
                    pre = cur;
                } else {
                    pre->next = cur;
                    pre = cur;
                }

                if (cur->left) {
                    que.push(cur->left);
                }

                if (cur->right) {
                    que.push(cur->right);
                }
            }

            pre->next = nullptr;
        }
        return root;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    TreeNode *root = buildTree(v);
    TreeNode *result = Solution().solve(root);
    cout << printTree(result) << endl;
}
