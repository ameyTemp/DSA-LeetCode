/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = l1;
        while(l1!=NULL and l2!=NULL){
            // cout<<l1->val<<l2->val<<endl;
            int sum = l1->val+l2->val;
            // cout<<sum<<endl;
            l1->val = sum;
            // cout<<l1->val<<endl;
            if(l1->next==NULL or l2->next==NULL)
                break;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2->next!=NULL){
            // cout<<1<<endl;
            l1->next=l2->next;
            l2=l2->next;
            l1=l1->next;
        }
        ListNode* t=temp;
        int carry = 0;
        while(t!=NULL){
            t->val+=carry;
            carry=0;
            if(t->val>=10){
                t->val-=10;
                carry=1;
            }
            if(t->next==NULL)
                break;
            t=t->next;
        }
        cout<<carry;
        if(carry==1){
            ListNode tempo;
            tempo.val += carry;
            t->next = new ListNode(carry);
        }
        return temp;
    }
};