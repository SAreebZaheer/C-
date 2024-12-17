#include <iostream>

using namespace std;

// Node structure for BST
struct Node {
    int rollno; // Student Roll No
    Node* left;
    Node* right;

    Node(int val) {
        rollno = val;
        left = NULL;
        right = NULL;
    }
};

// Function to insert student into the BST
Node* addStudent(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->rollno) {
        root->left = addStudent(root->left, key);
    } else if (key > root->rollno) {
        root->right = addStudent(root->right, key);
    }

    return root;
}

// Function to search for a student in the BST
bool findStudent(Node* root, int key) {
    if (root == NULL) {
        return false;
    }

    if (root->rollno == key) {
        return true;
    } else if (key < root->rollno) {
        return findStudent(root->left, key);
    } else {
        return findStudent(root->right, key);
    }
}

// Function to display all students in sorted order
void displayStudents(Node* root) {
    if (root != NULL) {
        displayStudents(root->left);
        cout << root->rollno << " ";
        displayStudents(root->right);
    }
}

int main() {
    Node* root = NULL; // Initialize the root of the BST to NULL
    int choice, rollno;

    while (true) {
        cout << "\nStudent Roll Number Management System\n";
        cout << "1. Add a student\n";
        cout << "2. Search for a student\n";
        cout << "3. Display all students (in sorted order)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the roll number to add: ";
            cin >> rollno;
            root = addStudent(root, rollno);
            cout << "Student added successfully.\n";
        } else if (choice == 2) {
            cout << "Enter the roll number to search: ";
            cin >> rollno;
            if (findStudent(root, rollno)) {
                cout << "Student with roll number " << rollno << " is in the system.\n";
            } else {
                cout << "Student not found.\n";
            }
        } else if (choice == 3) {
            cout << "Students in the system (sorted by roll number): ";
            displayStudents(root);
            cout << endl;
        } else if (choice == 4) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}