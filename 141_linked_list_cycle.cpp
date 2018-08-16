#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

bool hasCycle(ListNode *head) {
    if(head==NULL) return 0;
    if(head->next==head) return 1;
    ListNode *fast, *slow;
    fast=slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        // cout<<fast->val<<endl;
        // cout<<slow->val<<endl;
        if(slow==fast)
            return 1;
    }
    return 0;
}

int main(){
    ListNode *n1 = new ListNode(1);
    ListNode *n2= new ListNode(2);
    n1->next=n2;
    n2->next=n1;
    // cout<<n1->val<<endl;
    // cout<<n2->val<<endl;
    cout<<hasCycle(n1)<<endl;
    return 0;
}