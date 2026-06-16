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
    ListNode *solve(ListNode *head, int x) {
        ListNode *smallDummy = new ListNode(0);
        ListNode *bigDummy = new ListNode(0);

        ListNode *smallCur = smallDummy;
        ListNode *bigCur = bigDummy;

        ListNode *cur = head;
        while (cur) {
            if (cur->val < x) {
                smallCur->next = cur;
                smallCur = smallCur->next;
            } else {
                bigCur->next = cur;
                bigCur = bigCur->next;
            }
            cur = cur->next;
        }

        smallCur->next = bigDummy->next;
        bigCur->next = nullptr;
        return smallDummy->next;
    }
};

// =====================================================================
// 主函数: 输入 → 调用 Solution → 输出
// =====================================================================
int main() {
    vector<int> v = {1, 4, 3, 2, 5, 2};
    ListNode *head = buildList(v);
    int x = 3;
    ListNode *result = Solution().solve(head, x);
    printList(result);
}
