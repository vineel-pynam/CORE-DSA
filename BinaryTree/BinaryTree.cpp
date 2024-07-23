#include<bits/stdc++.h>
using namespace std;

// void init_code(){
// 	#ifndef ONLINE_JUDGE
// 		freopen("input.txt", "r", stdin);
// 		freopen("output.txt", "w", stdout);
// 	#endif
// }

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

class BinaryTree{
public:
	Node* root;
	BinaryTree(){
		this->root = NULL;
	}

	Node* buildTree(Node* root){
		cout << endl << "Enter a value: ";
		int value;
		cin >> value;
		if(value == -1 ) return NULL;

		root = new Node(value);
		root->left = buildTree(root->left);
		root->right = buildTree(root->right);
		return root;
	}

	void create(){
		this->root = this->buildTree(this->root);
	}

	void preorder(Node* root){
		if(!root) return;
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}

	void inorder(Node* root){
		if(!root) return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

	void postorder(Node* root){
		if(!root) return;
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
};

int main(){
	// init_code();

	BinaryTree bt;
	bt.create();

	cout << "PreOrder: ";
	bt.preorder(bt.root);
	cout << endl;

	cout << "InOrder: ";
	bt.inorder(bt.root);
	cout << endl;

	cout << "PostOrder: ";
	bt.postorder(bt.root);
	cout << endl;
}