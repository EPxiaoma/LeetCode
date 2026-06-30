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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);

        int index = 0;
        for (index; index < inorder.size(); index++) {
            if (inorder[index] == root->val) {
                break;
            }
        }

        vector<int> inLeft(inorder.begin(), inorder.begin() + index);
        vector<int> inRight(inorder.begin() + index + 1, inorder.end());

        vector<int> postLeft(postorder.begin(), postorder.begin() + index);
        vector<int> postRight(postorder.begin() + index, postorder.end() - 1);

        root->left = traversal(inLeft, postLeft);
        root->right = traversal(inRight, postRight);

        return root;
    }

    TreeNode *solve(vector<int> &inorder, vector<int> &postorder) {
        return traversal(inorder, postorder);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *result = Solution().solve(inorder, postorder);
    cout << printTree(result) << endl;
}
