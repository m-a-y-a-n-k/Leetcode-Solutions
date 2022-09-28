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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head -> next){
            return NULL; 
        }
        
        ListNode *ahead = head, *behind = head;
        
        while(n > 0 && ahead){
            ahead = ahead -> next;
            n--;
        }
        
        if(!ahead){
            return head -> next;
        }
        
        while(ahead && behind && ahead -> next){
            ahead = ahead -> next;
            behind = behind -> next;
        }
        
        if(behind){    
            behind -> next = behind -> next -> next;
        }
        
        return head;
    }
};