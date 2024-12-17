#include <iostream>

using namespace std;

struct Node
{
    int key;
    int height;
    Node *left;
    Node *right;

    Node(int key)
    {
        this->key = key;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree
{
public:
    Node *root;

    AVLTree()
    {
        root = nullptr;
    }

    int height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }

        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node; // Duplicate key
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left-Left Case
        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }

        // Right-Right Case
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }

        // Left-Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right-Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            Node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }

        if (root == nullptr)
        {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        // Left-Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
        {
            return rightRotate(root);
        }

        // Left-Right Case
        if (balance > 1 && getBalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right-Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
        {
            return leftRotate(root);
        }

        // Right-Left Case
        if (balance < -1 && getBalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void preorder(Node *root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void postorder(Node *root)
    {
        if (root != nullptr)
        {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

    void printTree()
    {
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    cout << "Creating Tree: " << endl;

    cout << "Adding 5,3,10,2,4,7,11,1,6,9,12,8" << endl;
    
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 3);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 2);
    tree.root = tree.insert(tree.root, 4);
    tree.root = tree.insert(tree.root, 7);
    tree.root = tree.insert(tree.root, 11);
    tree.root = tree.insert(tree.root, 1);
    tree.root = tree.insert(tree.root, 6);
    tree.root = tree.insert(tree.root, 9);
    tree.root = tree.insert(tree.root, 12);
    tree.root = tree.insert(tree.root, 8);

    cout << "Tree before deleting 5" << endl;
    tree.preorder(tree.root);

    cout << endl;

    cout << "Deleting 5" << endl;
    tree.root = tree.deleteNode(tree.root, 5);

    cout << "Tree after deleting 5" << endl;
    tree.preorder(tree.root);
    cout << endl;

       return 0;
}