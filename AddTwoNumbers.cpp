class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int delt = 0;
        ListNode* ans = nullptr;
        ListNode* cur = nullptr;
        while (l1 != nullptr || l2 != nullptr || delt > 0) {
            int f = 0;
            int sec = 0;
            if (l1 != nullptr) {
                f = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sec = l2->val;
                l2 = l2->next;
            }
            ListNode* tmp = new ListNode();
            tmp->val = (f + sec + delt) % 10;
            if (f + sec + delt > 9)
                delt = 1;
            else
                delt = 0;

            if (ans == nullptr) {
                ans = tmp;
                cur = ans;
            }
            else {
                cur->next = tmp;
                cur = cur->next;
            }
        }
        return ans;
    }
};
