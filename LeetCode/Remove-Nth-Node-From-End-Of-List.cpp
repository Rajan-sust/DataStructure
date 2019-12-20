/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) {
            return head;
        }
        int N = 0;
        ListNode *it = head;
        while(it) {
            N += 1;
            it = it->next;
        }
        int pos = N-n+1;
        ListNode *temp = head;
        if(pos == 1) {
            head = head->next;
            delete temp;
            return head;
        }
        int step = pos - 2;
        while(step--) {
            temp = temp->next;
        }
        ListNode *can = temp->next;
        temp->next = can->next;
        delete can;
        return head;
        
        
    }
};
