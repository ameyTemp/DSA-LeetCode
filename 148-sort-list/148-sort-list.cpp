/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     List Node *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode * mid = getMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        
        return merge(left,right);
    }
    
    ListNode * getMid(ListNode* head){
        ListNode* slow = NULL;
        while(head  and head->next){
            if(!slow)
                slow=head;
            else
                slow=slow->next;
            head=head->next->next;
        }
        ListNode * mid = slow->next;
        slow->next=NULL;
        return mid;
    }
    
    ListNode * merge(ListNode *l1,ListNode *l2){
        ListNode * dummy = new ListNode();
        ListNode *temp = dummy;
        while(l1 and l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1){
            temp->next=l1;
        }else if(l2){
            temp->next=l2;
        }
        
        return dummy->next;
    }
};