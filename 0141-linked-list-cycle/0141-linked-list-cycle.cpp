class Solution {
public:
    bool hasCycle(ListNode *head) {
        // If the list is empty or has only one node, it can't have a cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         
            fast = fast->next->next;    
            
            if (slow == fast) {
                return true;
            }
        }
        
        return false; 
    }
};