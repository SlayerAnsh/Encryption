#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* left = NULL;
    Node* right = NULL;
};

class BinaryTree{
private:
    Node* root;
    queue<Node*> q;
public:
    BinaryTree(){
        root = NULL;
    }
    void AddNode(char data){
        Node *temp = new Node;
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

    int height(Node* temp){
        if(temp == NULL)
            return 0;
        else{
            int h = height(temp->left);
            return h+1;
        }
    }

    void recur(Node *temp,int space){
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
    void Print(){
        int space = 0;
        recur(root,space);
    }

    void swaplevel(Node *temp,int level){
        char data;
        if(temp->right!=NULL){
            if(level%2==0){
                data = temp->left->data;
                temp->left->data = temp->right->data;
                temp->right->data = data;
            }
            
            swaplevel(temp->left,level+1);
            swaplevel(temp->right,level+1);
        }
        
        return;
    }
    void swapAlter(){
        swaplevel(root,0);
    }

    string SingleLevel(Node* temp, int i){
        if(temp==NULL){
            return "";
        }
        string str = "";
        if(i==1){
            str = temp->data;
        }
        else if(i>1){
            str.append(SingleLevel(temp->left,i-1));
            str.append(SingleLevel(temp->right,i-1));
        }
        return str;
    }
    string LevelOrderTraversal(){
        int h = height(root);
        string coded = "";
        for(int i = 1; i<=h; i++)
            coded.append(SingleLevel(root,i));
        return coded;
    }

};

string encrypt(string message){
    if(sizeof(message)==0){
        cout<<"ERROR : No data found in message\n";
        return "ERROR";
    }
    BinaryTree* temp = new BinaryTree;
    int i = 1;
    for(auto n : message){
        if(i%2==0){
            // cout<<(int)n+i-1<<"\t";
            temp->AddNode((n+(i-1))%256);
        }
        else{
            // cout<<(int)n+i+1<<"\t";
            temp->AddNode((n+(i+1))%256);
        }
        i++;
    }
    temp->swapAlter();
    message = temp->LevelOrderTraversal();
    
    return message;
}

string decrypt(string message){
    if(sizeof(message)==0){
        cout<<"ERROR : No data found in message\n";
        return "ERROR";
    }

    BinaryTree* temp = new BinaryTree;
    for(auto n: message)
        temp->AddNode(n);

    temp->swapAlter();

    message = temp->LevelOrderTraversal();
    int size = sizeof(message)/sizeof(message[0]);
    for(int i=1;i<=size;i++){
        if(i%2==0){
            message[i-1] = (message[i-1] - (i-1))%256;
        }
        else{
            message[i-1] = (message[i-1] - (i+1))%256;
        }
    }

    return message;
}



int main(){

    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string c = encrypt("Don't Try this at home");
    cout<<"Encrypted message : "<<c;

    cout<<"\nDecrypted message : "<<decrypt(c);

    return 0;
}

