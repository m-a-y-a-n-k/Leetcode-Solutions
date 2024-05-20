/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    if(!head){
        return head;
    }
    if(!head.next){
        return head;
    }
    const tail = head.next;
    const reversedHead = reverseList(head.next);
    tail.next = head;
    head.next = null;
    return reversedHead;
};