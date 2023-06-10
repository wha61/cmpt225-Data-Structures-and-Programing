#include<iostream>

using namespace std;

class AVLTree
{
public:
    class Node;
    Node *root;
    int count;

    class Node{
        public:
            int data;
            Node *left;
            Node *right;
            int height;
            //constructor
            Node(int data){
                this->data = data;
                this->left = nullptr;
                this->right = nullptr;
                this->height = 1;
            }
            //destructor
            ~Node(){
                delete left;
                delete right;
            }
            //getmax
            int max(int a, int b){  
                return (a > b)? a : b;  
            }
            //print the node
            void print(Node *root){
                if(root == nullptr){
                    cout << "L (0)"; 
                }
                else{
                    cout << root->data << " (" << root->height << ")";
                }        
            }
            };

public:
    //constructor
    AVLTree(){
        root = nullptr;
        count = 0;
    }
    //constructor
    ~AVLTree(){
        delete root;
    }
    // if the tree has a Node with key k, return it;
    // else, return a reference to a special Node end.
    Node* find(int k){
        return find(root,k);
    }
    // adds k to the AVLTree (duplicates are allowed), and returns its Node.
    Node* put(int k){
        root = put(root,k);
        return find(root,k);
    }
    // erase an entry with the key k.
    void erase(int k){
        root = erase(root,k);
    }
    // number of elements in the AVL Tree
    int size(){
        return count;
    }
    // is size == 0
    bool empty(){
        return (this->size() == 0);
    }
    // returns the special Node end
    Node* getEnd(){
        return getEnd(root);
    }
    int getHeight(Node *N){  
        if (N == NULL)  
            return 0;  
        return N->height;  
    }
    void print(){
        print(root,"");
    }

//get end
    Node* getEnd(Node *root){
        if(root == nullptr)
            return nullptr;
        Node* temp = root;
        while(temp->right != nullptr){
            temp = temp->right;
        }
        return temp;
    }
//find
    Node* find(Node *root,int key){
        if(root == NULL)
            return NULL;

        if(root->data == key)
            return root;

        if(key > root->data)
            return find(root->right,key);
        else
            return find(root->left,key);
    } 

//put
    Node* rebalanceForPut(Node *root, int bal, int key){
        if(bal < -1) // RIGHT
        {
            if(key < root->right->data) // Right-Left case
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            else // Right-Right Case
            {
                return leftRotate(root);
            }
        }
        else if(bal > 1)// LEFT
        {
            if(key < root->left->data) // Left-Left case
            {
                return rightRotate(root);
            }
            else // Left-Right Case
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        return root;
    }
    Node* put(Node *root,int key){
        if(root == nullptr){
            Node *newNode = new Node(key); //Making a new node
            count++;
            return newNode;
        }
        if(key > root->data){
            root->right = put(root->right,key); // puting at right
        }   
        else{
            root->left = put(root->left,key); //puting at left
        }
        // updating root's height
        root->height = 1 + max(getHeight(root->left),getHeight(root->right));
        int bal = getBalance(root); // checking the balance factor of the root

        return rebalanceForPut(root, bal,key);
    }

//erase
    Node* rebalanceForErase(Node *root, int bal, int key){
        if(bal < -1) // RIGHT
        {
            if(getBalance(root->right) > 0) // Right-Left case
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            else // Right-Right Case
            {
                return leftRotate(root);
            }
        }
        else if(bal > 1)// LEFT
        {
            if(getBalance(root->left) > 0) // Left-Left case
            {
                return rightRotate(root);
            }
            else // Left-Right Case
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        return root;
    }   
    Node* minValueNode(Node* node){  
        Node* current = node;  
        /* loop down to find the leftmost leaf */
        while (current->left != nullptr){
            current = current->left;
        }  
        return current;  
    }
    Node* erase(Node *root, int key)
    {

        if (root == NULL)  
            return root;  
        if (key < root->data){
            root->left = erase(root->left, key);
        }    
        else if(key > root->data ){
            root->right = erase(root->right, key); 
        }     
        else{  
            if( (root->left == NULL) || (root->right == NULL) ){  
                Node *temp = root->left ? root->left : root->right;  
                if (temp == NULL){  
                    temp = root;  
                    root = NULL;  
                }  
                else
                    *root = *temp;  
                free(temp);  
            }  
            else{  
                Node* temp = minValueNode(root->right); 
                root->data = temp->data;   
                root->right = erase(root->right,temp->data);  
            }  
        }  
        if (root == NULL)  
        return root;  

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));   
        int balance = getBalance(root);

        count--; 
        return rebalanceForErase(root, balance,key);
    }

// Get Balance factor of node N  
    int getBalance(Node *N){  
        if (N == nullptr)  
            return 0;  
        return getHeight(N->left) - getHeight(N->right);  
    } 

//left&&right rotation
    Node* rightRotate(Node *y){  
        Node *x = y->left;  
        Node *T2 = x->right; 
        // Perform rotation  
        x->right = y;  
        y->left = T2;  
        // Update heights  
        y->height = max(getHeight(y->left),getHeight(y->right)) + 1;  
        x->height = max(getHeight(x->left),getHeight(x->right)) + 1;  
        // Return new root  
        return x;  
    }
    Node* leftRotate(Node *x){  
        Node *y = x->right;  
        Node *T2 = y->left;  
        // Perform rotation  
        y->left = x;  
        x->right = T2;  
        // Update heights  
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;  
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;  
        // Return new root  
        return y;  
    }  

//print function
    void print(Node *root,string indent){
        if(root == nullptr){
            cout << indent << "L (0)" << endl;
            return;
        }  
        else{
            cout << indent << root->data << ' ' << '(' << root->height << ')' << endl;
            print(root->left,indent + " ");
            print(root->right,indent + " ");
        }   
    }
};
