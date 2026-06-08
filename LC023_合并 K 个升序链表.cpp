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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1) {
            cur->next = l1;
        }

        if (l2) {
            cur->next = l2;
        }
        return dummy->next;
    }

    ListNode *merge(vector<ListNode *> &lists, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;
        ListNode *l1 = merge(lists, left, mid);
        ListNode *l2 = merge(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode *solve(vector<ListNode *> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<vector<int> > v = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    vector<ListNode *> lists;
    for (auto &a: v) {
        lists.push_back(buildList(a));
    }

    ListNode *result = Solution().solve(lists);

    printList(result);
}
