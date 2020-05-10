/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 */
class MinStack {
   public:
    /** initialize your data structure here. */
    /* 方式2 使用一个栈， 每次入栈是 */
    /*
    使用一个栈：在栈里保存 v=(x-min), v:栈里面的值， x：实际的数， min：当前最小值 ， 这样实际值可以通过 x+v 计算得到。
    若 v >0  若明x > min， 这时候min不变化
    若 v <0  若明x < min， 这时候min 用x替换
    */
    /** initialize your data structure here. */
    MinStack() {}
    //
    void push(int x) {
        s.push(x);
        //如果压入的值小于辅助栈的栈顶元素值，则更新最小值（辅助栈压入新元素），否则辅助栈再次压入其栈顶元素
        if (smin.empty() || x <= smin.top())
            smin.push(x);
        else
            smin.push(smin.top());
    }

    void pop() {
        s.pop();
        smin.pop();  //出栈后，更新辅助栈
    }

    int top() { return s.top(); }

    int getMin() {
        return smin.top();  //辅助栈栈顶元素为最小值
    }

   private:
    stack<int> s;
    stack<int> smin;  //辅助栈
};

// class MinStack {
//    public:
//     /** initialize your data structure here. */
//     /* 方式1 使用双栈， 数据栈，和最小值辅助栈 */
//
//     stack<int> data;
//     stack<int> min_val;
//     MinStack() {}

//     void push(int x) {
//         data.push(x);
//         if (min_val.empty() || x <= min_val.top()) {
//             min_val.push(x);
//         }
//     }

//     void pop() {
//         if (data.top() == min_val.top()) {
//             data.pop();
//             min_val.pop();
//         } else {
//             data.pop();
//         }
//     }

//     int top() { return data.top(); }

//     int getMin() { return min_val.top(); }
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
