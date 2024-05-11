/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {
    let countA = 0, countB = 0;
    let ptrA = headA, ptrB = headB;
    while(ptrA){
        ptrA = ptrA.next;
        countA++;
    }
    while(ptrB){
        ptrB = ptrB.next;
        countB++;
    }
    ptrA = headA, ptrB = headB;
    while(countA > countB){
        ptrA = ptrA.next;
        countA--;
    }
    while(countB > countA){
        ptrB = ptrB.next;
        countB--;
    }
    while(ptrA && ptrB && ptrA != ptrB){
        ptrA = ptrA.next;
        ptrB = ptrB.next;
    }
    if(ptrA == ptrB){
        return ptrA;
    }
    return null;
};