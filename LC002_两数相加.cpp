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
    ListNode *solve(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        int carry = 0;

        while (l1 || l2 || carry != 0) {
            int val1 = 0;
            if (l1) {
                val1 = l1->val;
            }

            int val2 = 0;
            if (l2) {
                val2 = l2->val;
            }

            int sum = val1 + val2 + carry;
            ListNode *nextNode = new ListNode(sum % 10);
            carry = sum / 10;
            cur->next = nextNode;
            cur = cur->next;

            if (l1) {
                l1 = l1->next;
            }

            if (l2) {
                l2 = l2->next;
            }
        }

        return dummy->next;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    ListNode *l1 = buildList({9, 9, 9, 9, 9, 9, 9});
    ListNode *l2 = buildList({9, 9, 9, 9});
    ListNode *result = Solution().solve(l1, l2);
    printList(result);
}
