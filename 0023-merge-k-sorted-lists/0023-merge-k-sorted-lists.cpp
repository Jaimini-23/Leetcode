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
    ListNode* merge(ListNode* t1, ListNode* t2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 != NULL && t2 != NULL) {
            if(t1->val < t2->val) {
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
            }
            else {
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
            }
        }
        if(t1) temp->next = t1;
        else temp->next = t2;
        return dummyNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++) {
            head = merge(head,lists[i]);
        }
        return head;
    }
};