# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
  
            
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = num2 = 0
        pos = 1
        while l1 != None:
            num1 += l1.val * pos
            pos *= 10
            l1 = l1.next
        #endwhile
        pos = 1
        while l2 != None:
            num2 += l2.val * pos
            pos *= 10
            l2 = l2.next
        #endwhile
        num = num1 + num2
        head = None
        while True:
            digit = num % 10
            num //= 10
            if head == None:
                head = cur = ListNode(digit)
            else:
                temp = cur.next = ListNode(digit)
                cur = temp
            #endif
            if num == 0:
                break
            #endif
        #endwhile
        return head