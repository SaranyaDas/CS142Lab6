/*Implement Binary Search Tree (BST)
1. insert()
2. display()
3. search()
*/
#include<iostream>
using namespace std;
//class node
class node {
      public:
      int data;
      //filial nodes
      node*left;
      node*right;
      //default constructor
      node(int value) { 
            left = NULL;
            right = NULL;
            data = value;
      }
};
//class BST for the tree
class BST {
      public:
      //roooooooooooooot
      node*root; 
      //default constructor
      BST() {
           root = NULL;
      }
      //1. insert()
      void insert(int value) {
           ins(root, value); //sets current = root
           }
      void ins(node*current, int value) {
           if(root == NULL) { 
                   root = new node(value);
           }
           else {
                   if(value < current -> data) {
                            if(current -> left == NULL) {
                                       current -> left = new node(value);
                            }
                            else {
                                       ins(current -> left, value);
                            }
                   }
                   else {
                            if(current -> right == NULL) {
                                       current -> right = new node(value);
                            }
                            else {
                                       ins(current -> right, value);
                            }
                   }
           }
      }
      //2. display()
      void display() {
           dis(root); //sets current = root
           cout << endl;
      }
      void dis(node*current) {
           if(current == NULL) {
                      return;
           }
           //display left
           dis(current -> left);
           //display current
           cout << current -> data << ", ";
           //display right
           dis(current -> right);
      }
      //3. search()
      node*search(int value) {
           return src(root, value); //sets current = root
      }
      node*src(node*current, int value) {
           if(current == NULL || current -> data == value) {
                      return current;
           }
           else {
                      if(value < current -> data) {
                               return src(current -> left, value); //go left
                      }
                      else {
                               if(value > current -> data) {
                                        return src(current -> right, value); //go right
                               }
                      }
           }
      }
};
//main function
int main() {
    BST NMB48;
    NMB48.insert(5);
    NMB48.insert(2);
    NMB48.insert(8);
    NMB48.insert(1);
    NMB48.insert(6);
    NMB48.insert(4);
    NMB48.insert(7);
    NMB48.insert(3);
    NMB48.display();
    cout << NMB48.search(3) << endl;
    cout << NMB48.search(3) -> data << endl;
    return 0;
}
