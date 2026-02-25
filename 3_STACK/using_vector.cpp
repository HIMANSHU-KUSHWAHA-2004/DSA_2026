#include<bits\stdc++.h>
using namespace std;

class Stack{
    vector<int> v;

    public:
        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();
        }
        int top(){
            return v[v.size() - 1];
        }
        bool empty(){
            return v.size() == 0;
        }
};
int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    while(!s1.empty()){
        cout << s1.top() << "\n";
        s1.pop();
    }
}