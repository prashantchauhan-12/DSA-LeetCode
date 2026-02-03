/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* mover = head;
        ListNode* moverPrev = NULL;

        while (mover != NULL) {
            ListNode* temp = mover->next;

            mover->next = moverPrev;
            moverPrev = mover;
            mover = temp;
        }

        return moverPrev;
    }
};