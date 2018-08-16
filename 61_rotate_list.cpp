#include<bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* rotateRight(ListNode* head, int k) {
    if(head==NULL || head->next==NULL)
        return head;
    int l=0;
    ListNode *p,*f,*s;
    p=head;
    while(p){
        l++;
        p=p->next;
    }
    k=k%l;
    if(k==0)
        return head;
    s=f=head;
    for(int i=0;i<k;i++){
        f=f->next;
    }
    while(f->next){
        f=f->next;
        s=s->next;
    }
    f->next=head;
    p=s->next;
    s->next=NULL;
    return p;
}

int main(){

    return 0;
}