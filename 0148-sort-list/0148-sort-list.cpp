#include <vector>
#include <algorithm>

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        std::vector<int> arr;
        ListNode* curr = head;
        while (curr != nullptr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        
        std::sort(arr.begin(), arr.end());
        
        curr = head; 
        for (int i = 0; i < arr.size(); i++) {
            curr->val = arr[i];
            curr = curr->next;
        }
        
        return head;
    }
};