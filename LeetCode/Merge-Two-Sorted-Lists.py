# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        merged_list = []
        while l1 != None  and l2 != None:
            if l1.val <= l2.val:
                merged_list.append(l1.val)
                l1 = l1.next
            else:
                merged_list.append(l2.val)
                l2 = l2.next
            #endif
        #endwhile
        while l1 != None:
            merged_list.append(l1.val)
            l1 = l1.next
        while l2 != None:
            merged_list.append(l2.val)
            l2 = l2.next
        
        head = None
        for val in merged_list:
            if head == None:
                head = cur = ListNode(val)
            else:
                temp = cur.next = ListNode(val)
                cur = temp
        return head
