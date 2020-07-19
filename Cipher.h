#ifndef CIPHER_H
#define CIPHER_H


#include<string>
#include"BinaryTree.h"
using namespace std;

string firstLevelEncrypt(string message);
string secondLevelEncrypt(string message);
string encrypt(string message);

string firstLevelDecrypt(string message);
string secondLevelDecrpt(string message);
string decrypt(string message);

#endif