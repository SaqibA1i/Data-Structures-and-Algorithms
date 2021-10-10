#include <iostream>
#include <vector>
template<typename T>

// left is smaller then root
class BinarySearchTree{
    struct Node {
        T value;
        Node* left;
        Node* right;
    };
    private:
        Node* root;
        void add_helper(Node* node,T val){
            Node* p_traverse = node;
            // Base Case i.e. nullptr
            
            if(p_traverse->right->val < val){
                add_helper(, T val)
            }
        }
    public:
        BinarySearchTree(){};
        BinarySearchTree(T val){
            root->value = val;
            root->left = nullptr;
            root->right = nullptr;
        }
        void add(T val){
            add_helper(root,val);
        }
};