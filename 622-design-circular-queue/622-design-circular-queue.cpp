class MyCircularQueue {
    int front = 0, rear = 0, size = 0, cap = 0;
    
    vector<int> CQ;
    
public:
    MyCircularQueue(int k) {
        cap = k;
        CQ.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(isEmpty()){
            front = rear = 0;
            CQ[rear] = value;
            size++;
            return true;
        }
        
        rear++;
        rear %= cap;
        CQ[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        front++;
        front %= cap;
        
        size--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : CQ[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : CQ[rear];        
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */