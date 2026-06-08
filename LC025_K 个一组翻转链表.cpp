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
    void traversal(ListNode *start, ListNode *end) {
        ListNode *pre = nullptr;
        ListNode *cur = start;
        ListNode *stop = end->next;
        while (cur != stop) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
    }

    ListNode *solve(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *preNode = dummy;

        while (preNode->next) {
            int step = k;
            ListNode *end = preNode;
            while (step--) {
                end = end->next;
                if (end == nullptr) {
                    return dummy->next;
                }
            }

            ListNode *start = preNode->next;
            ListNode *nextNode = end->next;
            traversal(start, end);

            preNode->next = end;
            start->next = nextNode;
            preNode = start;
        }

        return dummy->next;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    ListNode *head = buildList(v);
    int k = 2;
    ListNode *result = Solution().solve(head, k);
    printList(result);
}
