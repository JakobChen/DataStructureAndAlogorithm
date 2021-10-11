#include<iostream>
#include<vector>
using namespace std;



class MyStack{
private:
    vector<int> data;// store elements
public:

    bool pop(){
        if(isEmpty()){
            return false;
        }
        else{
            data.pop_back();
        }
        return true;
    }
    /** Insert an element into the stack. */

    void push(int val){
        data.push_back(val);
    }
    int size(){
        return data.size();
    }
    bool isEmpty(){
        return data.empty();
    }
    /** Get the top item from the queue. */
    int top(){
        return data.back();
    }
};


int main(){

    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    for (int i = 0; i < 4; ++i) {
        if (!s.isEmpty()) {
            cout << s.top() << endl;
        }
        cout << (s.pop() ? "true" : "false") << endl;
    }
}