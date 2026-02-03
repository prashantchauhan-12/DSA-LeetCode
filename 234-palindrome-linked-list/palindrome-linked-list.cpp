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
    ListNode* front;
    bool check(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        bool isPal = check(head->next) && front->val == head->val;

        front = front->next;

        return isPal;
    }

    bool isPalindrome(ListNode* head) {
        front = head;
        return check(head);
    }
};