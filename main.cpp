#include<iostream>
#include"BinaryTree.h"
#include"Cipher.h"

using namespace std;

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string message = "TEST script with 123";
    message = encrypt(message);
    cout<<"\nENCRYPT : "<<message;
    cout<<"\nDECRYPT : "<<decrypt(message);

    return 0;
}
