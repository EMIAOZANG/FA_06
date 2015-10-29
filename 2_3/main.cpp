#include <iostream>

using namespace std;

class TreeNode{
 public:
   int val;
   int even;
   TreeNode* left;
   TreeNode* right;
   TreeNode* parent;

   TreeNode(int _val, int _even)
     :val(_val),even(_even),left(NULL),right(NULL),parent(NULL){}
   
};

class BSTree{
 public:
   TreeNode* root;

   TreeNode* find(int _val){
     TreeNode* current = root;
     while (current != NULL){
       if (current->val == _val){
         return current;
       }
       else if (_val < current->val){
         current = current->left;
       }
       else{
         current = current->right;
       }
     }
     return NULL;
   }

   TreeNode* successor(TreeNode* v){
     
   }

   bool insert(int _val){
     TreeNode* v = new TreeNode(_val,0);
     TreeNode* up = NULL;
     TreeNode* down = root;

     while (down != NULL){
       up = down;
       if ((up != NULL) && (_val%2 == 0)){
         up->even++;
       }
       if (_val < down->val){
         down = down->left;
       }
       else{
         down = down->right;
       }
     }

     v->parent = up;
     if (up == NULL){
       root = v;
     }
     else if (v->val < up->val){
       up->left = v;
     }
     else {
       up->right = v;
     }
     return true;
     
   }

   bool remove(TreeNode* v){
     //find y
     TreeNode* y = NULL;
     if ((v->right == NULL) || (v->left == NULL)){
       y = v;
     } 
     else {
       y = successor(root);
     }
     return true;
     
   }

};


