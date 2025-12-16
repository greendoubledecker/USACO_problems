#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int creatingIndex = 0;

struct Node{
	int value = 0;
	Node* lChild;
	Node* rChild;
	int leftIndex = -1;
	int rightIndex = -1;
};

Node* buildTree(vector<int> leaves){
	if(leaves.size() == 1){
		Node* node = new Node;
		node->value = leaves[0];
		node->lChild = nullptr;
		node->rChild = nullptr;
		node->leftIndex = creatingIndex; //inclusive!
		node->rightIndex = creatingIndex;
		++creatingIndex;
		return node;
	}
	Node* root = new Node;
	int halfSize = leaves.size() / 2;
	vector<int> leftLeaves(leaves.begin(), leaves.begin() + halfSize);
	vector<int> rightLeaves(leaves.begin() + halfSize, leaves.end());
	Node* left = buildTree(leftLeaves);
	Node* right = buildTree(rightLeaves);
	root->lChild = left;
	root->rChild = right;
	root->leftIndex = root->lChild->leftIndex;
	root->rightIndex = root->rChild->rightIndex;
	root->value = root->lChild->value + root->rChild->value;
	return root;
}

int queryTree(Node* root, int left, int right){ //left and right are inclusive
	if(root->leftIndex > right){
		return 0;
	}
	if(root->rightIndex < left){
		return 0;
	}
	if(root->leftIndex >= left && root->rightIndex <= right){
		return root->value;
	}
	return queryTree(root->lChild, left, right) + queryTree(root->rChild, left, right);
}

void printTree(Node* root, int level){
	for(int i = 0; i < level; ++i){
		cout << "  ";
	}
	cout << "->";
	cout << root->value << endl;
	if(root->lChild != nullptr && root->rChild != nullptr){
		printTree(root->lChild, level + 1);
		printTree(root->rChild, level + 1);
	}
}

int main(){
	int n;
	cout << "Enter the number of values, then the values themselves(space-separated)." << endl;
	cin >> n;
	vector<int> leaves(n);
	for(int i = 0; i < n; ++i){
		cin >> leaves[i];
	}
	Node* root = buildTree(leaves);
	cout << "Here's the tree visualization!" << endl;
	printTree(root, 0);
	cout << "Enter the range to be summed up(left and right indices, inclusive)." << endl;
	int l, r;
	cin >> l >> r;
	cout << "The sum is " << queryTree(root, l, r) << endl;
}
