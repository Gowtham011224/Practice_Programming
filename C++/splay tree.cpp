#include <iostream>
using namespace std;

template <class T>
class SplayTree {
public:
    struct Node {
        T key;
        Node* left;
        Node* right;
        Node(T k) : key(k), left(nullptr), right(nullptr) {}
    };

    Node* root;

    SplayTree() : root(nullptr) {}

    Node* zig(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    Node* zag(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    Node* splay(Node* root, int key) {
        if (!root || root->key == key)
            return root;

        if (root->key > key) {
            if (!root->left) return root;

            if (root->left->key > key) {
                root->left->left = splay(root->left->left, key);
                root = zig(root);
            } else if (root->left->key < key) {
                root->left->right = splay(root->left->right, key);
                if (root->left->right)
                    root->left = zag(root->left);
            }
            return (root->left == nullptr) ? root : zig(root);
        } else {
            if (!root->right) return root;

            if (root->right->key > key) {
                root->right->left = splay(root->right->left, key);
                if (root->right->left)
                    root->right = zig(root->right);
            } else if (root->right->key < key) {
                root->right->right = splay(root->right->right, key);
                root = zag(root);
            }
            return (root->right == nullptr) ? root : zag(root);
        }
    }

    void insert(int key) {
        if (!root) {
            root = new Node(key);
            return;
        }

        root = splay(root, key);

        if (root->key == key) return;

        Node* newNode = new Node(key);
        if (root->key > key) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }
        root = newNode;
    }

    void deleteKey(int key) {
        if (!root) return;

        root = splay(root, key);

        if (root->key != key) return;

        if (!root->left) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else {
            Node* temp = root;
            root = splay(root->left, key);
            root->right = temp->right;
            delete temp;
        }
    }

    void search(int key) {
        root = splay(root, key);
        if (root && root->key == key) {
            cout << "Found " << key << endl;
        } else {
            cout << "Not Found " << key << endl;
        }
    }

    void preOrder(Node* root) {
        if (root) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void inOrder(Node* root) {
        if (root) {
            inOrder(root->left);
            cout << root->key << " ";
            inOrder(root->right);
        }
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void postOrder(Node* root) {
        if (root) {
            postOrder(root->left);
            postOrder(root->right);
            cout << root->key << " ";
        }
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};

int main() 
{
    SplayTree<int> tree;
    int choice, key;

    while (true) 
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Inorder Traversal";
        cout << "\n6. Postorder Traversal";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                tree.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                tree.deleteKey(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                tree.search(key);
                break;
            case 4:
                tree.preOrder();
                break;
            case 5:
                tree.inOrder();
                break;
            case 6:
                tree.postOrder();
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
