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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL;
        if(!list1){
            return head = list2;
        }
        if(!list2){
            return head = list1;
        }
        head = list1;
        bool useFirst = true;
        if(list2 && head -> val > list2 -> val){
            head = list2;
            useFirst = false;
        }        
        ListNode *next = NULL;
        if(useFirst){
            head -> next = mergeTwoLists(head -> next, list2);
        } else {
            head -> next = mergeTwoLists(list1, head -> next);
        }
        return head;
    }
};
