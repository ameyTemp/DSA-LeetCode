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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
    
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        temp=head;
        for(int i=0;i<len-n-1;i++){
            temp=temp->next;
        }
        if(len==1 and n==1){
            return NULL;
        }
        if(len==1){
            temp->next=NULL;
        }else if(n==len){
              head=head->next; 
        }else{
            ListNode* temp2 = temp->next->next;
            temp->next=temp2;
        }
        // cout<<temp->val<<endl;
        return head;
    }
};