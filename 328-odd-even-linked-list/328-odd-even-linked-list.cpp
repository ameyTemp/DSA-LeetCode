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
        ListNode *even=head,*odd=head->next;
        ListNode *oddhead=odd;
        while(odd!=NULL and odd->next!=NULL){
            even->next=odd->next;
            even=even->next;
            odd->next=even->next;
            odd=odd->next;
        }
        even->next=oddhead;
        return head;
    }
};