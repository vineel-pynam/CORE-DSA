#include<bits/stdc++.h>
using namespace std;

void init_code(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

class Queue{

public: 
	int capacity;
	int front = -1;
	int rear = -1;
	int* store;

	Queue(int capacity){
		this->capacity = capacity;
		this->store = new int[capacity];
	}

	void push(int value){
		if( !isFull() ){
			if( front == -1 ) front = 0;
			cout << "Pushed: " << value << endl;
			store[++rear] = value;
		}else{
			cout << "Queue is full"<<endl;
		}
	}

	void pop(){
		if( !isEmpty() ){
			cout << "Popped: " << this->peek() << endl;
			front++;

			if( front > rear ){
				front = rear = -1;
			}

		}else{
			cout << "Queue is Empty" << endl;
		}
	}

	int peek(){
		return store[front];
	}

	bool isFull(){
		return rear == this->capacity-1;
	}

	bool isEmpty(){
		return front==-1 && rear == -1;
	}
};

int main(){
	init_code();

	Queue q(3);
	q.pop();

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << "Front: " << q.peek() << endl;
	q.pop();
	cout << "Front: " << q.peek() << endl;
	q.pop();
	cout << "Front: " << q.peek() << endl;
	q.pop();
	cout << "Front: " << q.peek() << endl;
}
