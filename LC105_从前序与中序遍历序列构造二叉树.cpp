#include <bits/stdc++.h>
using namespace std;


// =====================================================================
// 二叉树
// =====================================================================

// 二叉树数据结构
struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {
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
    TreeNode *traversal(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[0]);

        int index = 0;
        for (index; index < inorder.size(); index++) {
            if (inorder[index] == root->val) {
                break;
            }
        }

        vector<int> preLeft(preorder.begin() + 1, preorder.begin() + 1 + index);
        vector<int> preRight(preorder.begin() + 1 + index, preorder.end());

        vector<int> inLeft(inorder.begin(), inorder.begin() + index);
        vector<int> inRight(inorder.begin() + index + 1, inorder.end());

        root->left = traversal(preLeft, inLeft);
        root->right = traversal(preRight, inRight);

        return root;
    }

    TreeNode *solve(vector<int> &preorder, vector<int> &inorder) {
        return traversal(preorder, inorder);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *result = Solution().solve(preorder, inorder);
    cout << printTree(result) << endl;
}
