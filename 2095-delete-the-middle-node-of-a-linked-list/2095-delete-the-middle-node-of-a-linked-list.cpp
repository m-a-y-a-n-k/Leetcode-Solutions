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
        if(!head || !head -> next){
            return NULL;
        }
        ListNode *slow = head, *fast = head, *pre = NULL;
        
        while(fast){
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
                pre = slow;
                slow = slow -> next;
            }
        }        
        
        if(pre && slow)
            pre -> next = slow -> next;
        
        return head;
    }
};