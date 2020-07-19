#ifndef BINARYTREE_H
#define BINARYTREE_H 

#include<queue>
#include<string>
#include<stack>
using namespace std;

struct Node{
	char data;
	Node* left = NULL;
	Node* right = NULL;
};

class BinaryTree {
private:
	Node* root;
	queue<Node*> q,tq;
public:
	BinaryTree();
	~BinaryTree();

	void addNode(char data);
	void createLevelTree(string message);

	void swapLevel(Node* temp, int level);
	void swapAlter();

	string levelTraversal();

	void recur(Node* temp, int space);
	void print();

	void deleteTree(Node* temp);
	
};

#endif