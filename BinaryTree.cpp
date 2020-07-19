#include<iostream>
#include "BinaryTree.h"
using namespace std;




BinaryTree::BinaryTree(){
	root = NULL;
}
BinaryTree::~BinaryTree(){

}
void BinaryTree::addNode(char data){
	Node* temp = new Node;
	temp->data = data;
	if(root == NULL)
		root = temp;
	else if(q.front()->left == NULL){
            q.front()->left = temp;
    }
    else{
        q.front()->right = temp;
        q.pop();
    }
    q.push(temp);
    return;
}

void BinaryTree::createLevelTree(string message){
	for(auto n: message){
		addNode(n);
	}
}

void BinaryTree::swapLevel(Node* temp, int level){
	char data;
	if(temp->right!=NULL){
		if(level%2==0){
			data = temp->left->data;
            temp->left->data = temp->right->data;
            temp->right->data = data;
		}
		swapLevel(temp->left,level+1);
        swapLevel(temp->right,level+1);
	}
	return;
}

void BinaryTree::swapAlter(){
	if(root!=NULL)
		swapLevel(root,0);
}

string BinaryTree::levelTraversal(){
	string message = "";
	if(root==NULL)
		return "";
	tq.push(root);
	while(tq.empty() == false){
		message.push_back(tq.front()->data);
		if(tq.front()->left!= NULL)
			tq.push(tq.front()->left);
		if(tq.front()->right!=NULL)
			tq.push(tq.front()->right);
		tq.pop();
	}
	return message;
}

void BinaryTree::recur(Node* temp, int space){
    if(temp->right != NULL){
        recur(temp->right,space + 1);
    }
    for(int i=0;i<space;i++)
        cout<<"\t";
    cout<<temp->data<<"\n";

    if(temp->left!=NULL){
        recur(temp->left, space + 1);
    }

    return;
}

void BinaryTree::print(){
	recur(root,0);
}

