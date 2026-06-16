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
// 核心代码
// =====================================================================
class Solution {
public:
    ListNode *solve(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;

        while (cur->next && cur->next->next) {
            int val1 = cur->next->val;
            int val2 = cur->next->next->val;
            if (val1 == val2) {
                while (cur->next && cur->next->val == val2) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> v = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head = buildList(v);
    ListNode *result = Solution().solve(head);
    printList(result);
}
