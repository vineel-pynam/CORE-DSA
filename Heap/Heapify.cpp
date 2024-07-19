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
	int* store;
	int size;
	Heap(int store[], int size){
		this->store = store;
		this->size = size;
	}

	void heapify(int index){

		int smallest = index;
		int left = 2*index;
		int right = 2*index + 1;
		if( left<=size && store[left] < store[smallest] ){
			smallest = left;
		}

		if( right<=size && store[right] < store[smallest] ){
			smallest = right;
		}

		if( smallest != index ){
			swap(store[smallest], store[index]);
			heapify(smallest);
		}
	}

	void createHeap(){
		for(int i=size/2; i>=1; i-- ){
			this->heapify(i);
		}
	}

	int top(){
		return store[1];
	}

	void display(){
		for( int i=1; i<=size; i++ ){
			cout << store[i] << " ";
		}
		cout << endl;
	}

};

int main(){
	init_code();

	int n;
	cin >> n;

	int arr[n+1];
	arr[0] = -1;
	for( int i=1; i<=n; i++ ){
		cin >> arr[i];
	}

	Heap heap(arr, n);
	heap.createHeap();
	heap.display();
	heap.top();
}