#include<bits/stdc++.h>
using namespace std;

void init_code(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
}

class Heap{

public:
	int capacity;
	int size;
	int* store;
	Heap(int capacity){
		this->capacity = capacity;
		this->size = 0;
		this->store = new int[capacity];
	}

	void push(int value){
		if( isFull() ){
			cout << "Heap is Full" << endl;
			return;
		}

		size++;
		int index = size;
		store[index] = value;

		for( int i=index/2; i>=1; i/=2 ){
			if( store[i] > store[index] ){
				swap(store[i], store[index]);
				index = i;				
			}
		}
	}

	void pop(){
		if( isEmpty() ){
			cout << "Heap is Empty" << endl;
			return;
		}

		cout << "Popped: " << this->top() << endl;
		swap(store[1], store[size]);
		size--;

		int index = 1;
		while( index < size ){
			int left = 2*index;
			int right = 2*index + 1;

			int smallest = index;
			if( left<=size && store[left] < store[smallest] ){
				smallest = left;
			}

			if( right<=size && store[right] < store[smallest]){
				smallest = right;
			}

			if( smallest != index ) {
				swap(store[smallest], store[index]);
				index = smallest;
			}else{
				return;
			}

		}

	}

	int top(){
		return store[1];
	}

	bool isFull(){
		return size == capacity;
	}

	bool isEmpty(){
		return size == 0;
	}

	void display(){
		if( isEmpty() ){
			cout << "Heap is Empty" << endl;
			return;
		}

		for( int i=1; i<=size; i++ ){
			cout << store[i] << " ";
		}
		cout << endl;
	}

};

int main(){
	init_code();

	Heap heap(7);

	heap.push(1);
	heap.push(4);
	heap.push(3);
	heap.push(6);
	heap.push(10);
	heap.push(9);
	heap.push(11);
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
	heap.pop();
	heap.display();
}