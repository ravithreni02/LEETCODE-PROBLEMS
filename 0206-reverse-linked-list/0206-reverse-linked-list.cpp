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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevnode,*currentnode,*nextnode;
        prevnode=0;
        currentnode=nextnode=head;
        while(nextnode!=0){
            nextnode=nextnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }
        head=prevnode;
    return prevnode;
        
    }

};