# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


def getNumber(l):
    num = 0
    pos = 1
    while l != None:
        num += l.val * pos
        pos *= 10
        l = l.next
    #endwhile
    return num

class Solution:
  
            
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num = getNumber(l1) + getNumber(l2)
        head = current = None
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