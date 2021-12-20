//organization_tree

#include <bits/stdc++.h>
using namespace std;

struct node{
	string position;
	node *first, *second;
};

struct org_tree{
	node *root;
	static org_tree create_org_structure(const string& pos)
	{
		org_tree tree;
		tree.root = new node{pos, NULL, NULL};
		return tree;
	}
	static node* find(node* root, string& value){
		if(root == NULL)
			return NULL;
		if(root->position == value)
			return root;
		
		auto firstFound = org_tree::find(root->first, value);
		if(firstFound != NULL)
			return firstFound;
		return org_tree::find(root->second, value);
	}
	bool addSubordinate(string manager, string subordinate)
	{
		auto managerNode = org_tree::find(root, manager);
		if(!managerNode){
			cout << "No position named: " << manager << endl;
			return false;
		}
		if(managerNode->first && managerNode->second){
			cout << manager << " has two subordinates." << endl;
			return false;
		}
		else{
			auto subNode = new node{subordinate, NULL, NULL};
			if(managerNode -> first){
				managerNode->second = subNode;
			}
			else
				managerNode->first = subNode;
			return true;
		}
	}
};

int main(){
	auto tree = org_tree::create_org_structure("CEO");
	if(tree.addSubordinate("CEO", "Deputy Director"))
		cout << "Deputy Director added." << endl;
	else
		cout << "Couldn't add Deputy Director." << endl;
	
	if(tree.addSubordinate("Deputy Director", "IT Head"))
		cout << "Added IT Head";
	else
		cout << "Couldn't add IT Head";
	cout << endl;
	
	if(tree.addSubordinate("IT Head", "Security Head"))
		cout << "Added Security Head" << endl;
	else
		cout << "Could not add Security Head" << endl;
	
	return 0;
}
