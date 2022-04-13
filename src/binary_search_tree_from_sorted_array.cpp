#include <iostream>
#include <vector>

struct Tree {
    int data_;
    Tree* left_;
    Tree* right_;
};
Tree* initialize(int data) {
    Tree *node   = new Tree;
    // TODO: check if allocation is failed
    
    node->data_  = data;
    node->left_  = nullptr;
    node->right_ = nullptr;
    
    return node;
}
void add_node(Tree** node, int data) {
    if (*node == nullptr) {
        *node = initialize(data);
        return;
    }
    if (data < (*node)->data_) {
        add_node(&((*node)->left_), data);
        return;
    } 
    if (data > (*node)->data_) {
        add_node(&((*node)->right_), data);
        return;
    }
}
void print_intendation(int spaces) {
    for (int index = 0; index < spaces; ++index)
        std::cout << '\t';
}
void print_tree(Tree *root, int spaces = 0) {
    if (!root)
        return;
    print_intendation(spaces);
    std::cout << root->data_ << '\n';
    print_tree(root->right_, spaces + 1);
    print_tree(root->left_,  spaces + 1);
}

void add_nodes_from_sorted_array(Tree **root, const std::vector<int> &numbers, int begin, int end) {
    if (end - begin < 1)
        return;
    const int middle_index = (end + begin) / 2;
    add_node(root, numbers[middle_index]);
    
    add_nodes_from_sorted_array(root, numbers, begin, middle_index);
    add_nodes_from_sorted_array(root, numbers, middle_index + 1, end);
}
void deallocate_tree(Tree **root) {
    if (*root == nullptr)
        return;

    deallocate_tree(&((*root)->left_));
    deallocate_tree(&((*root)->right_));
    
    delete *root;
    *root = nullptr;
}
int main() {
    Tree *root = nullptr;
    const std::vector<int> numbers {-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19,20};
    const int begin = 0;
    const int end = numbers.size();
    add_nodes_from_sorted_array(&root, numbers, begin, end);
    
    print_tree(root);
    deallocate_tree(&root);
    return 0;
}