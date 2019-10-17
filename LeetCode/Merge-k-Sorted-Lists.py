# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from Queue import PriorityQueue

class Solution:
    def mergeKLists(self, lists):
        head = pointer = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
            #endif
        #endfor
        while not q.empty():
            val, node = q.get()
            pointer.next = ListNode(val)
            pointer = pointer.next
            node = node.next
            if node:
                q.put((node.val, node))
            #endif
        #endwhile
        return head.next
