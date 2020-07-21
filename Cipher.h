#ifndef CIPHER_H
#define CIPHER_H


#include<string>
#include"BinaryTree.h"
using namespace std;

string firstLevelEncrypt(string message);
string secondLevelEncrypt(string message);
string encrypt(string message);
void encryptFile(string filename);

string firstLevelDecrypt(string message);
string secondLevelDecrpt(string message);
string decrypt(string message);
void decryptFile(string filename);

#endif