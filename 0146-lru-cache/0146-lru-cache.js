/**
 * @param {number} capacity
 */

class Node {
    constructor(key, val){
        this.key = key;
        this.value = val;
        this.next = null;
        this.prev = null;
    }
}

class DLL {
    constructor() {
        this.head = new Node(null, null);
        this.tail = new Node(null, null);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    addNode(node) {
        node.prev = this.head;
        node.next = this.head.next;
        this.head.next.prev = node;
        this.head.next = node;
    }

    removeNode(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    moveToHead(node) {
        this.removeNode(node);
        this.addNode(node);
    }

    popTail() {
        let res = this.tail.prev;
        this.removeNode(res);
        return res;
    }
}


var LRUCache = function(capacity) {
    this.capacity = capacity;
    this.cache = new Map();
    this.list = new DLL();
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    let node = this.cache.get(key);
    if (!node) {
        return -1;
    }
    this.list.moveToHead(node);
    return node.value;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    let node = this.cache.get(key);
    if (node) {
        node.value = value;
        this.list.moveToHead(node);
    } else {
        let newNode = new Node(key, value);
        this.cache.set(key, newNode);
        this.list.addNode(newNode);

        if (this.cache.size > this.capacity) {
            let tail = this.list.popTail();
            this.cache.delete(tail.key);
        }
    }
};

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */