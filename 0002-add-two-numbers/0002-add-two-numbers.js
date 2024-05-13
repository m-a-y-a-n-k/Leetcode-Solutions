/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let head = new ListNode(0);
    const start = head;
    let carry = 0;
    let pre = null;
    
    while(l1 || l2){
        head.val = (l1?.val || 0) + (l2?.val || 0) + carry;
        carry = Math.floor(head.val / 10);
        head.val %= 10;
        pre = head;
        head.next = new ListNode(0);
        head = head.next;
        if(l1){
            l1 = l1.next;
        }
        if(l2){
            l2 = l2.next;
        }
    }
    
    if(carry){
        head.val += carry;
    } else {
        pre.next = null;
    }
    
    return start;
};