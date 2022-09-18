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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *curr = NULL, *temp = NULL;
        int c = 0;
        while(l1 != NULL || l2 != NULL){
            int a = 0;
            if(!l2){
                temp = new ListNode(l1 -> val);            
            } else if(!l1){
                temp = new ListNode(l2 -> val);                            
            } else {
                temp = new ListNode(l1 -> val);
                a = l2 -> val;
            }
            if(!head){
                head = curr = temp;
            }
            temp -> val = temp -> val + a + c;
            c = temp -> val / 10;
            temp -> val %= 10;                
            if(l1 != NULL)
                l1 = l1 -> next;
            if(l2 != NULL)
                l2 = l2 -> next;
            if(head != temp){
                curr -> next = temp;
                curr = temp;
            }
        }
        if(c){
            temp = new ListNode(1);
            curr -> next = temp;
        }
        return head;
    }
};