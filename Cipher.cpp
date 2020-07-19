#include<iostream>
#include"Cipher.h"

using namespace std;

string firstLevelEncrypt(string message){
	for(int i=1;i<=message.length();i++){
		if(i%2==0)
			message[i-1] = (message[i-1] + (i-1))%256;
		else
			message[i-1] = (message[i-1] + (i+1))%256;
	}
	return message;
}

string secondLevelEncrypt(string message){
	BinaryTree tree;
	tree.createLevelTree(message);
	tree.swapAlter();
	message = tree.levelTraversal();
	return message;	
}

string encrypt(string message){
	if(sizeof(message)==0){
		cout<<"ERROR : No data found\n";
		return "";
	}
	message = firstLevelEncrypt(message);
	message = secondLevelEncrypt(message);
	return message;
}

string firstLevelDecrypt(string message){
	BinaryTree tree;
	tree.createLevelTree(message);
	tree.swapAlter();
	message = tree.levelTraversal();
	return message;
}

string secondLevelDecrypt(string message){
	for(int i=1;i<=message.length();i++){
		if(i%2==0)
			message[i-1] = (message[i-1] - (i-1))%256;
		else
			message[i-1] = (message[i-1] - (i+1))%256;			
	}
	return message;
}

string decrypt(string message){
	if(sizeof(message)==0){
		cout<<"ERROR : No data found to decrypt\n";
		return "";
	}
	message = firstLevelDecrypt(message);
	message = secondLevelDecrypt(message);
	return message;
}