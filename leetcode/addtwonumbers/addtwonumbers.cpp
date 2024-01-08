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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *current = result;
        ListNode *l1next = l1, *l2next = l2;
        bool isCarried = false;
        int val1 = 0, val2 = 0;
        do{
            if(l1next != nullptr){
                val1 = l1next->val;
                l1next = l1next->next;
            }else{
                val1 = 0;
                l1next = nullptr;
            }
            if(l2next != nullptr){
                val2 = l2next->val;
                l2next = l2next->next;
            }else{
                val2 = 0;
                l2next = nullptr;
            }
            int val = val1 + val2;
            if(isCarried){
                val += 1;
                isCarried = false;
            }
            current->val = val % 10;
            if(val > 9){
                isCarried = true;
            }
            
            if(l1next == nullptr && l2next == nullptr && !isCarried){
                break;
            }

            current->next = new ListNode();
            current = current->next;
        }while(true);

        return result;
    }
}; 
