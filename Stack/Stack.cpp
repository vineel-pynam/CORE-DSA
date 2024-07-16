#include<bits/stdc++.h>
using namespace std;

void init_code(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

class Stack{

public: 
	int capacity;
	int* store;
	int top;
	Stack(int capacity){
		this->capacity = capacity;
		this->store = new int[capacity];
		this->top = -1;
	}

	void push(int value){
		if( !isFull() ){
			cout << "Pushed: " << value << endl;
			store[++top] = value;
		}else{
			cout << "Stack is Full" << endl;
		}
	}

	void pop(){
		if( !isEmpty() ){
			cout << "Popped: " << this->peek() << endl;
			top--;
		}else{
			cout << "Stack is Empty" << endl;
		}
	}

	int peek(){
		return store[top];
	}

	bool isFull(){
		return top == this->capacity-1;
	}

	bool isEmpty(){
		return top == -1;
	}

};

int main(){
	init_code();

	Stack stack(5);
	stack.pop();

	stack.push(1);
	stack.push(2);	
	cout << "Peek: " <<  stack.peek() << endl;
	stack.pop();
	stack.pop(); 
	stack.pop();
	stack.push(1);
	stack.push(2);	
	stack.push(3);
	stack.push(4);	
	stack.push(5);
	stack.push(6);	
}