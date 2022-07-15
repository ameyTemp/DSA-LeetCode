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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* even=new ListNode(head->val);
        ListNode* odd=new ListNode(head->next->val);    
        ListNode *temp=head;
        ListNode* temp1=even,*temp2=odd;
        temp=temp->next->next;
        int count=1;
        while(temp!=NULL){
            if(count%2==0){
                odd->next=new ListNode(temp->val);
                odd=odd->next;
            }else{
                even->next=new ListNode(temp->val);
                even=even->next;
            }
            temp=temp->next;
            count++;
        }
        even->next=temp2;
        return temp1;
    }
};