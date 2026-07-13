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
    ListNode* getkthnode(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL&&k>0){
            k--;
            temp=temp->next;

        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode*prevlast=NULL;
        while(temp!=NULL){
            ListNode* kthnode=getkthnode(temp,k);
            if(kthnode==NULL){
                if(prevlast)  prevlast->next=temp;
                break;
            }
             ListNode* nextnode=kthnode->next;
             kthnode->next=NULL;
            reverseList(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevlast->next=kthnode;
            }
            prevlast=temp;
            temp=nextnode;

        }
        return head;
       
    }
};