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

    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr) {
            return head;
        }
        
        if(head->next == nullptr) {
            return head;
        }
        
        ListNode *prev = nullptr, *cur = head, *temp;
        
        while(true) {
            
            if(cur->next == nullptr) {
                cur->next = prev;
                head = cur;
                break;
            }
            
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        return head;
       
    }
    
    
};