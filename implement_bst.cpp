//implementing bst

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left, *right;
};

struct bst{
	node *root = nullptr;
	
	node* find(int val){
		return find_impl(root, val);
	}
	node* find_impl(node* current, int val){
		if(!current){
			cout << endl;
			return NULL;
		}
		if(current->data == val){
			cout << "Found " << val << endl;
			return current;
		}
		if(val > current->data){
			cout << "Going right" << endl;
			return find_impl(current->right, val);
		}
		else{
			cout << "Going left" << endl;
			return find_impl(current->left, val);
		}
	}
	public:
		void insert(int value){
			if(!root)
				root = new node{value, NULL, NULL};
			else
				insert_impl(root, value);
		}
	private:
		void insert_impl(node* current, int value){
			if(value > current->data){
				if(!current->right)
					current->right = new node{value, NULL, NULL};
				else
					insert_impl(current->right, value);
			}
			else{
				if(!current->left)
					current->left = new node{value, NULL, NULL};
				else
					insert_impl(current->left, value);
			}
		}
	public:
		void inorder(){
			inorder_impl(root);
		}
	private:
		void inorder_impl(node* current){
			if(!current)
				return;
			
			inorder_impl(current->left);
			cout << current->data << " ";
			inorder_impl(current->right);
		}
	public:
		node* successor(node* start){
			auto current = start->right;
			while(current && current->left)
				current = current->left;
			
			return current;
		}
		void deleteValue(int value){
			delete_impl(root, value);
		}
	private:
		node* delete_impl(node* current, int value){
			if(!current)
				return NULL;
			if(value < current->data)
				current->left = delete_impl(current->left, value);
			else if(value > current->data)
				current->right=delete_impl(current->right, value);
			else{
				if(!current->left){
					auto tmp = current->right;
					delete current;
					return tmp;
				}
				if(!current->right){
					auto tmp = current->left;
					delete current;
					return tmp;
				}
				
				node* sucNode = successor(current);
				current->data = sucNode->data;
				current->right = delete_impl(current->right, sucNode->data);
			}
		return current;
		}
};

int main(){
	bst tree;
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);
	cout << "Inorder: ";
	tree.inorder();
	cout << endl;
	tree.deleteValue(12);
	
	cout << "Inorder after deleting 12: ";
	tree.inorder();
	cout << endl;
	
	if(tree.find(12))
		cout << "12 present" << endl;
	else
		cout << "12 absent" << endl;
		
	return 0;
}
