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

   TreeNode* minimum(TreeNode* v){
     TreeNode* current = v;
     while (v->left != NULL){
       current = current->left;
     }
     return current; 
   }

   TreeNode* successor(TreeNode* v){
    if (v->right != NULL){
      return minimum(v);
    } 
    TreeNode* y = v->parent;
    while ((y != NULL) && (v == y->left)){
      v = v->parent;
      y = y->parent;
    }
    return v;
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

   TreeNode* remove(TreeNode* v){
     //Returns the parent of the deleted ndoe y
     //find y
     TreeNode* y = NULL;
     TreeNode* trace_start = NULL;
     TreeNode* x = NULL;
     if ((v->right == NULL) || (v->left == NULL)){
       y = v;
     } 
     else {
       y = successor(root);
     }
     trace_start = y->parent;
     
     if (y->right != NULL){
       x = y->right;
     }
     x->parent = y->parent;
     if (x->parent == NULL){
       root = x;
     }
     
     if (y == y->parent->left){
       x = y->parent->left;
     }
     else {
       x = y->parent->right;
     }
     //delete the point
     


     return y->parent;
     
   }

};


