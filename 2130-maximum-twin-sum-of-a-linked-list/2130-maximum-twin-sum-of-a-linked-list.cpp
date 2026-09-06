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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        while(current != NULL) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* find(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
        }
        ListNode* reverseHead = reverse(slow->next);
        return reverseHead;
    }
    int pairSum(ListNode* head) {
        ListNode* left = head;
        ListNode* right = find(head);
        int twinSum = INT_MIN;
        while(right != NULL) {
            int temp = left->val + right->val;
            twinSum = max(temp,twinSum);
            right = right->next;
            left = left->next;
        }
        return twinSum;
    }
};