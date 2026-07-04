struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
        
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();
            
            tail->next = curr;
            tail = tail->next;
            if (curr->next != nullptr) {
                minHeap.push(curr->next);
            }
        }
        return dummy->next;
    }
};