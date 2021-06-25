#include <iostream> 
using namespace std; 

class TreeNode{
    int info; 
    TreeNode* left; 
    TreeNode* right; 
public: 
    TreeNode(){
        info = 0; 
        left = nullptr;
        right = nullptr; 
    }
    TreeNode(int i){
        info = i; 
        left = nullptr; 
        right = nullptr; 
    }
    TreeNode(int i, TreeNode* l, TreeNode* r){
        info = i; 
        left = l; 
        right = r; 
    }
    TreeNode* insert(TreeNode* rt, int val);
    void preorder(TreeNode* rt);  
    void inorder(TreeNode* rt);
    void postorder(TreeNode* rt);  
    bool findElement(TreeNode* rt, int search); 
};
TreeNode* TreeNode::insert(TreeNode* rt, int val){
    if (!rt)
    {
        // Insert the first TreeNode, if root is NULL.
        return new TreeNode(val);
    }
 
    // Insert data.
    if (val > rt->info)
    {
        // Insert right TreeNode data, if the 'value'
        // to be inserted is greater than 'root' TreeNode data.
        // Process right TreeNodes.
        rt->right = insert(rt->right, val);
    }
    else
    {
        // Insert left TreeNode data, if the 'value'
        // to be inserted is greater than 'root' TreeNode data.
        // Process left TreeNodes.
        rt->left = insert(rt->left, val);
    }
    // Return 'root' TreeTreeNode, after insertion.
    return rt;
}

bool TreeNode::findElement(TreeNode* rt, int search){

    if(rt == nullptr)
        return false; 
        
//checks if the curr node info  == the  search item
    if(rt->info == search)
       return true;

//then recur the left sub tree
    bool found = findElement(rt->left, search); 
    if(found)
        return true;

//then recur on the right side if not found on the left side
    bool found2 = findElement(rt->right, search); 
    if(found2)
        return found2; 

}

 void TreeNode::preorder(TreeNode* rt){
    TreeNode* curr = rt; 
     if(curr != nullptr){
         cout << curr->info << " "; 
         preorder(curr->left); 
         preorder(curr->right); 
     }
 }
void TreeNode::inorder(TreeNode* rt){
     TreeNode* curr = rt; 
     if(curr != nullptr){
         inorder(curr->left); 
         cout << curr->info << " "; 
         inorder(curr->right); 
     }
 }
 void TreeNode::postorder(TreeNode* rt){
     TreeNode* curr = rt; 
     if(curr != nullptr){
         postorder(curr->left); 
         postorder(curr->right); 
         cout << curr->info << " "; 
     }
 }


int main(){
    TreeNode* root = nullptr; 

    root = root->insert(root,5);
    root->insert(root,6);
    root->insert(root,4);
    root->insert(root,7);
    root->insert(root,30);
    root->insert(root,1);
    root->insert(root,25);
    root->insert(root,3);
    root->preorder(root);
    cout << endl; 
    root->inorder(root); 
    cout << endl; 
    root->postorder(root);
    cout << endl; 
    cout << root->findElement(root,25);  



    return 0; 
}