#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> fifo_in;
    stack<int> fifo_out;
    // template<typename t>
    MyQueue() {
        fifo_in = stack<int>();
        fifo_out = stack<int>();
    }
    
    void push(int x) {
        while(!fifo_in.empty()){
            fifo_out.push(fifo_in.top());
            fifo_in.pop();
        }
        fifo_in.push(x);
        while(!fifo_out.empty()){
            fifo_in.push(fifo_out.top());
            fifo_out.pop();
        }
        
    }
    
    int pop() {
        int temp = fifo_in.top();
        fifo_in.pop();
        return temp;
    }
    
    int peek() {
        return fifo_in.top();
    }
    
    bool empty() {
        return fifo_in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */