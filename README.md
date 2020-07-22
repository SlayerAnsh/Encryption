# ENCRYPTION ALGORITHM
This is a simple example of cipher algorithm which uses **Binary Tree** for second level encryption.

### Cryptography
Cryptography is the practice and study of techniques for securing communication and data in the presence of adversaries.
In simple language, **Cryptography** is modifying your data in such a way that only you and the receiver know the real data while any other intermediate person (hacker, request, etc) cannot interpret the meaning of modified data.
Cryptography mainly include two steps [**ENCRYPTION**](#encryption) and [**DECRYPTION**](#decryption).

### ENCRYPTION
Encryption mainly include substituting and rearranging the order of the text in such a way that retrieving the original data without the help of key/algorithm will take very very long time (ideally it should not be possible to crack). In our code we are using two level Encryption. **First level encryption** uses **substitution** and **second level encryption** uses **Tree Traversal**. 

In our code, we are providing two ways to encrypt your data :
1. In `main.cpp` change default value of `string message` to your own message and comment decrypt part. You will get output of ebcrypted text for your message.
2. In `main.cpp` comment encrypt and decrypt and uncomment `encryptFile("filename")` part. In `filename` put the name of the file whose content you want to encrypt. After encryption the content of file will be encrypted.

### DECRYPTION
Decryptiion mainly include reverse traversing of encryption algorithm. Similar to the Encryption part we provide two ways to decrypt, either by `encrypted message` or `encrypted file`.

### EXECUTION OF THE CODE
Note : Relative links are used, therefore keep all files in same folder.

For Windows based system, make sure you have gcc/g++ installed. Check by running `g++ --version` in cmd. Once confirmed that g++/gcc is installed, open `cmd` and change the path to current directory where content of this repository are present. After that type `execute` in cmd, which will run `execute.cmd` file present in our repository.

In case the program stop working, press `Ctrl + C` to end the process.

If you want to edit the code, don't forget to go through all the header files and during execution link the object files properly.

Follow these steps if you want to manually link files :
1. open cmd and run `g++ -c *.cpp`
2. After completion without error, run `g++ -o main *.o`
3. Now for execution, run `main`

Note: You have to Link files every time you modify.

For Linux bases system, use `make` to automate the linking process.

You are invited to add your own encryption algorithms.
