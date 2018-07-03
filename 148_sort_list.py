class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None



def merge(h1,h2):
    if not h1: 
        return h2
    if not h2:
        return h1
    res=None
    if h1.val<h2.val:
        res=h1
        h1=h1.next
    else:
        res=h2
        h2=h2.next
    p=res
    while h1 and h2:
        if h1.val<h2.val:
            p.next=h1
            h1=h1.next
        else:
            p.next=h2
            h2=h2.next
        p=p.next
    if h1:
        p.next=h1
    if h2:
        p.next=h2
    return res

        
def list_sort(head):
    if not head or not head.next:
        return head
    fast=head
    slow=head
    while fast.next and fast.next.next:
        fast=fast.next.next
        slow=slow.next
    fast=slow
    slow=slow.next
    fast.next=None
    fast=list_sort(head)
    slow=list_sort(slow)
    return merge(fast,slow)