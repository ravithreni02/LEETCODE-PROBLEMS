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
    ListNode* deleteMiddle(ListNode* head) {
        // Base case: if the list has 0 or 1 node, deleting the middle leaves it empty
        if (head == nullptr || head->next == nullptr) {
            // REMOVED: delete head; -> Let LeetCode handle the original head node cleanup
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* middle = slow->next;
        slow->next = slow->next->next;
        
        delete middle; // This manual delete is correct because this node is disconnected from the returned list
        
        return head;
    }
};
