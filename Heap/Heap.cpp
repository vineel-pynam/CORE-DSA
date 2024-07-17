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
	int* store;
	int index = 1;
	Heap(int capacity){
		this->capacity = capacity;
		this->store = new int[capacity+1];
	}

	void push(int value){
		if( isFull() ){
			cout << "Heap is Full" << endl;
			return;
		}
		
		store[index] = value;

		int curr = index;
		for( int i=index/2; i>=1; i/=2){
			if( store[i] > store[curr] ){
				swap(store[i], store[curr]);
				curr = i;
			}
		}
		
		index++;
	}

	bool isFull(){
		return index > capacity;
	}

	void display(){
		for( int i=1; i<index; i++ ){
			cout << store[i] << " ";
		}
		cout << endl;
	}

};

int main(){
	init_code();

	Heap heap(5);

	heap.push(2);
	heap.push(10);
	heap.push(9);
	heap.push(1);
	heap.push(3);
	heap.display();


}