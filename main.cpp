#include<iostream>
#include"BinaryTree.h"
#include"Cipher.h"

using namespace std;

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Write your message here to encrypt/decrypt
    string message = "CODE RED";


   
    //comment this if DECRYPTING
    cout<<"\nENCRYPT : "<<encrypt(message);
	

    //Comment this for Encrypting
    cout<<"\nDECRYPT : "<<decrypt(message);

    
    //Use Below functions to encrypt files

    
    //Uncomment this for Encrypting file
    // cout<<"\nEncryting file...";
    // encryptFile("message.txt");

    
    //Uncomment this for Decrypting File
    // cout<<"\nDecrypting file...";
    // decryptFile("message.txt");

    return 0;
}
