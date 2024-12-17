#include <iostream>
using namespace std;

struct Node {
    int license_plate;
    Node* left;
    Node* right;

    Node(int lp) : license_plate(lp), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST() : root(nullptr) {}

    void insert(int license_plate) {
        root = insertRecursive(root, license_plate);
    }

    bool search(int license_plate) {
        return searchRecursive(root, license_plate);
    }

    void remove(int license_plate) {
        root = removeRecursive(root, license_plate);
    }

    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

private:
    Node* root;

    Node* insertRecursive(Node* node, int license_plate) {
        if (node == nullptr) {
            return new Node(license_plate);
        }

        if (license_plate < node->license_plate) {
            node->left = insertRecursive(node->left, license_plate);
        } else if (license_plate > node->license_plate) {
            node->right = insertRecursive(node->right, license_plate);
        }

        return node;
    }

    bool searchRecursive(Node* node, int license_plate) {
        if (node == nullptr) {
            return false;
        }

        if (license_plate == node->license_plate) {
            return true;
        } else if (license_plate < node->license_plate) {
            return searchRecursive(node->left, license_plate);
        } else {
            return searchRecursive(node->right, license_plate);
        }
    }

    Node* removeRecursive(Node* node, int license_plate) {
        if (node == nullptr) {
            return nullptr;
        }

        if (license_plate < node->license_plate) {
            node->left = removeRecursive(node->left, license_plate);
        } else if (license_plate > node->license_plate) {
            node->right = removeRecursive(node->right, license_plate);
        } else {
            // Node with one or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(node->right);
            node->license_plate = temp->license_plate;
            node->right = removeRecursive(node->right, temp->license_plate);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    void inorderTraversalRecursive(Node* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            cout << node->license_plate << " ";
            inorderTraversalRecursive(node->right);
        }
    }
};

int main() {
   

    BST parkingLot;

    while (true) {
        cout << "\nParking Lot Management System\n";
        cout << "1. Add a car\n";
        cout << "2. Search for a car\n";
        cout << "3. Remove a car\n";
        cout << "4. Display all cars\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int licensePlate;
                cout << "Enter the license plate number to add: ";
                cin >> licensePlate;
                parkingLot.insert(licensePlate);
                cout << "Car added.\n";
                break;
            }
            case 2: {
                int licensePlate;
                cout << "Enter the license plate number to search: ";
                cin >> licensePlate;
                if (parkingLot.search(licensePlate)) {
                    cout << "Car is in the parking lot.\n";
                } else {
                    cout << "Car not found.\n";
                }
                break;
            }
            case 3: {
                int licensePlate;
                cout << "Enter the license plate number to remove: ";
                cin >> licensePlate;
                parkingLot.remove(licensePlate);
                cout << "Car removed.\n";
                break;
            }
            case 4: {
                cout << "Cars in the parking lot (sorted order): ";
                parkingLot.inorderTraversal();
                cout << endl;
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
}