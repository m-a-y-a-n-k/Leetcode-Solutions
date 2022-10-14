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
        ListNode *slow = head, *fast = head;
        
        while(fast){
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
                slow = slow -> next;
            }
        }
        
        fast = head;
        
        while(fast){
            if(fast -> next == slow){
                break;
            }
            fast = fast -> next;
        }
        
        if(fast && fast -> next)
            fast -> next = fast -> next -> next;
        
        return head;
    }
};