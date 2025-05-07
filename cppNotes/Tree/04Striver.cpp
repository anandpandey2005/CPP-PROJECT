// ---------------   PREORDER TRAVERSAL
#include <iostream>
using namespace std;
class Tree
{
public:
    int data;
    Tree *left = NULL;
    Tree *right = NULL;

    Tree(int data) : data(data), left(nullptr), right(nullptr) {}
    //--------------- RECURSSIVE WAY
    void rPreorder(Tree *root)
    {
        if (!root)
            return;

        cout << root->data;

        rPreorder(root->left);
        rPreorder(root->right);
    }
    ~Tree();
};

int main()
{
    Tree *root = new Tree(1); // Root node

    root->left = new Tree(2);  // Left child of root
    root->right = new Tree(3); // Right child of root

    root->left->left = new Tree(4);  // Left child of node 2
    root->left->right = new Tree(5); // Right child of node 2

    root->right->left = new Tree(6);  // Left child of node 3
    root->right->right = new Tree(7); // Right child of node 3

    root->rPreorder(root);

    return 0;
}
