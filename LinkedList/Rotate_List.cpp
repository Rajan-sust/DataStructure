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
    
   int getLength(ListNode *head) {
       
       ListNode *it = head;
       int cnt = 0;
       
       while(it != NULL) {
           cnt += 1;
           it = it->next;
       }
       
       return cnt;
   }
    
    
    
    ListNode* rotateRight(ListNode *head, int k) {
        
        if(head == NULL){
            return head;
        } else if(head->next == NULL) {
            return head;
        }
        
        int len = getLength(head);
        k = k % len;
        
        if(k == 0) {
            return head;
        }
        
        int pos = len - k, cnt = 0;
        
        ListNode *rest , *it = head;
        
        while(it != NULL) {
            cnt += 1;
            if(cnt == pos) {
                rest = it->next;
                it->next = NULL;
                break;
            }
            it = it->next;
        }
        
        ListNode *last;
        it = rest;
        
        while(true) {
            if(it->next == NULL) {
                last = it;
                break;
            }
            it = it->next;
        }
        
        ListNode *temp_head = head;
        last->next = temp_head;
        head = rest;
        return head;
        
    }
};