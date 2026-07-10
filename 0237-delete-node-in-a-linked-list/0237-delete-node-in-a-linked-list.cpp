class Solution {
public:
    void deleteNode(ListNode* node) {
        // Overwrite the current node's value with the next node's value
        node->val = node->next->val;
        
        // Save the address of the next node to free its memory later
        ListNode* temp = node->next;
        
        // Link the current node to the node after next
        node->next = node->next->next;
        
        // Delete the redundant node to prevent memory leaks
        delete temp;
    }
};

