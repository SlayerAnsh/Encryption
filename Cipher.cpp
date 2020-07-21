#include<iostream>
#include <fstream>
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

void encryptFile(string filename){
	fstream file;
	file.open(filename);
	if(!file){
		cout<<"ERROR : File not found\n";
		return;
	}
	string str;
	int cur;
	while(!file.eof()){
		cur = file.tellg();
		getline(file,str);
		str = encrypt(str);
		file.seekg(cur,ios_base::beg);
		file<<str<<"\n";
        if(!file.eof())
            break;
	}
	file.close();
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

void decryptFile(string filename){
	fstream file;
	file.open(filename);
	if(!file){
		cout<<"ERROR : File not found\n";
		return;
	}
	string str;
	int cur;
	while(!file.eof()){
		cur = file.tellg();
		getline(file,str);
		str = decrypt(str);
		file.seekg(cur,ios_base::beg);
		file<<str<<"\n";
        if(!file.eof())
            break;
	}
	file.close();
}