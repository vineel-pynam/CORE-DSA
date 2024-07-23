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

	Node* deleteNode(Node* root, int value){
		if( !root ) return NULL;
		root->left = deleteNode(root->left, value);
		root->right = deleteNode(root->right, value);

		if( root->data == value ){
			if( !root->left ) return root->right;
			if( !root->right ) return root->left;

			Node* temp = root;
			while(temp->left != NULL){
				temp = temp->left;
			}

			temp->left = root->right;
			return root->left;
		}

		return root;
	}

	void remove(int value){
		this->root = this->deleteNode(this->root, value);
	}

	void levelOrder(){
		if( !this->root ) {
			cout << " Root is Null " << endl;
			return;
		}

		queue<Node*> q;
		q.push(this->root);

		while(!q.empty()){
			int size = q.size();

			for( int i=0; i<size; i++ ){
				Node* front = q.front();
				q.pop();
				cout << front->data << " ";
				if(front->left) q.push(front->left);
				if(front->right) q.push(front->right);
			}
		}

		cout << endl;

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

	cout << "levelOrder: ";
	bt.levelOrder();
	cout << endl;

	bt.remove(5);
	cout << "PreOrder: ";
	bt.preorder(bt.root);
	cout << endl;
}