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
      void insert(int value) { //dummy function
           insert(root, value); //sets current = root
           }
      void insert(node*current, int value) {
           if(current == NULL) { 
                   current = new node(value);
           }
           else {
                   if(value < current -> data) {
                            if(current -> left == NULL) {
                                       current -> left = new node(value);
                            }
                            else {
                                       insert(current -> left, value);
                            }
                   }
                   else {
                            if(current -> right == NULL) {
                                       current -> right = new node(value);
                            }
                            else {
                                       insert(current -> right, value);
                            }
                   }
           }
      }
      //2. display()
      void display() { //dummy function
           display(root); //sets current = root
           cout << endl;
      }
      void display(node*current) {
           if(current == NULL) {
                      return;
           }
           //display left
           display(current -> left);
           //display current
           cout << current -> data << ", ";
           //display right
           display(current -> right);
      }
      //3. search()
      node*search(int value) { //dummy function
           return search(root, value); //sets current = root
      }
      node*search(node*current, int value) {
           if(current == NULL || current -> data == value) {
                      return current;
           }
           else {
                      if(value < current -> data) {
                               return search(current -> left, value); //go left
                      }
                      else {
                               if(value > current -> data) {
                                        return search(current -> right, value); //go right
                               }
                      }
           }
      }
      //2D display
      void print2D() { //dummy function
           print2D(root, 0); //sets current = root 
      }  
      void print2D(node*current, int spaces) {  
           if(current == NULL) {
                       return;  
           }
           spaces += 5; 
           print2D(current -> right, spaces); 
           cout << endl;
           for(int i = 5; i < spaces; i++) {
                     cout << " ";  
                     cout << current -> data;
                     print2D(current -> left, spaces);
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
    cout << NMB48.search(3) -> data << endl;
    cout << NMB48.search(3) << endl;
    NMB48.print2D();
    cout << endl;
    return 0;
}
