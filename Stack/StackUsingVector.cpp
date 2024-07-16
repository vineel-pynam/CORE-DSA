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
	vector<int> s;
	Stack(int capacity){
		this->capacity = capacity;
	}

	void push(int value){
		if( !isFull() ){
			s.push_back(value);
			cout << "Pushed: " << value << endl;
		}else{
			cout << "Stack is Full" << endl;
		}
	}

	void pop(){
		if( !isEmpty() ){
			cout << "Popped: " << this->peek() << endl;
			s.pop_back();
		}else{
			cout << "Stack is Empty" << endl;
		}
	}

	int peek(){
		return s.back();
	}

	bool isFull(){
		return s.size() == this->capacity;
	}

	bool isEmpty(){
		return s.size() == 0;
	}

};

int main(){
	init_code();

	Stack stack(5);
	stack.pop();

	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.pop();
	cout << "Peek: " << stack.peek() << endl;
	stack.push(4);
	stack.push(5);
	stack.push(6);
	cout << "Peek: " << stack.peek() << endl;
	stack.push(7);
	cout << "Peek: " << stack.peek() << endl;
}


/// QUEUE

