#include<bits/stdc++.h>
using namespace std;

void init_code(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

class CircularQueue{

public: 
	int capacity;
	int* store;
	int front = -1;
	int rear = -1;
	CircularQueue(int capacity){
		this->capacity = capacity;
		this->store = new int[capacity];
	}

	void push(int value){
		if( !isFull() ){
			if( front == -1 ) front = 0;
			rear = (rear + 1) % this->capacity;
			store[rear] = value;
			cout << "Pushed: " << value << endl;
		}else{
			cout << "Queue is Full" << endl;
		}
	}

	void pop(){
		if( !isEmpty() ){
			cout << "Popped: " << this->peek() << endl;

			if( front == rear ){
				front = rear = -1;
			}else{
				front = (front+1) % this->capacity;
			}
		}else{
			cout << "Queue is Empty" << endl;
		}
	}

	int peek(){
		return store[front];
	}

	bool isFull(){
		return ((rear + 1) % this->capacity) == front;
	}

	bool isEmpty(){
		return front == -1 && rear == -1;
	}

};

int main(){
	init_code();

	CircularQueue q(5);
	q.pop();

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	cout << "Front: " << q.peek() << endl;
	q.pop();
	q.pop();

	q.push(6);
	q.push(7);
	
	q.push(8);
	q.pop();
	q.pop();
	cout << "Front: " << q.peek() << endl;
	q.pop();
	q.pop();
	q.pop();

	cout << q.front  << " " << q.rear << endl;

}