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
    int lenOfLL(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = lenOfLL(head);
        int pos = len - n + 1;
        if(pos == 1) {
            return head->next;
        }
        int cnt = 0;
        while(temp != NULL) {
            cnt++;
            if(cnt == pos - 1) break;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};