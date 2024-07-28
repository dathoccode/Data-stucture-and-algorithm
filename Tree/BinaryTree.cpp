#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *right;
    Node *left;
    Node()
    {
        cout << "this is constructor" << endl;
    }
    Node(T data, Node *right = NULL, Node *left = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    bool contain(T data)
    {
        if (this == NULL)
            return false;
        if (this->data > data)
            return this->left->contain(data);
        if (this->data < data)
            return this->right->contain(data);
        else
            return true;
    }
};

template<class T> Node<T>* FindMin(Node<T> *root)
{
    Node<T> *temp = root;
    while(temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

template<class T> void insert(Node<T>* &node, T data)
{
    if (node->contain(data))
        return;
    if (node == NULL)
        node = new Node(data);
    if (node->data >= data)
    {
        if (node->left == NULL)
        {
            node->left = new Node(data);
        }
        else
        {
            insert(node->left, data);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            node->right = new Node(data);
        }
        else
        {
            insert(node->right, data);
        }
    }
}

template<class T> Node<T>* remove(Node<T>* &node, T data)
{
    if(node == NULL) return node;
    if(node->data < data) node->right = remove(node->right, data);
    else if(node->data > data) node->left = remove(node->left, data);
    else 
    {
        // case 1: the node has no child
        if(node->left == NULL || node->right == NULL)
        {
            delete node;
            node = NULL;
        }
        //case 2: the node has 1 child
        else if(node->right != NULL) //the child is a right node
        {
            Node<T> *temp = node;
            node = node->right;
            delete temp;
        }
        else if(node->left != NULL) //the child is a left node
        {
            Node<T> *temp = node;
            node = node->left;
            delete temp;
        }
        //case 3: the node has 2 children
        else
        {
            //find the smallest element in the right sub-tree of the root. This node is greater than all nodes in the left sub-tree and smaller than all other nodes in the right sub-tree
            Node<T> *temp = FindMin(node->right); 
            node->data = temp->data;
            //delete the element used to replace deleted node
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

template<class T> void show(Node<T>* node)
{
    cout << node->data << " ";
    if(node->left) show(node->left);
    if(node->right) show(node->right);
}

int main()
{
    Node<int> *root = new Node(12);
    bool stop = true;
    while(stop)
    {
        cout << "-----------------MENU---------------\n";
		cout << "1. insert\n";
		cout << "2. remove\n";
		cout << "3. show\n";
        cout << "4. tim kiem\n";
        cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
        int input;
        cin >> input;
        switch(input)
        {
            case 1:
            {
                int data;
                cout << "nhap so can insert: ";
                cin >> data;
                insert(root, data);
                break;
            }
            case 2:
            {
                int data;
                cout << "nhap so can remove: ";
                cin >> data;
                remove(root, data);
                break;
            }
            case 3:
            {
                cout << "showing tree:" << endl;
                show(root);
                cout << endl;
                break;
            }
            case 4:
            {
                cout << "Nhap so can tim: ";
                int data; cin>> data;
                if(root->contain(data)) cout << "ton tai so can tim" << endl;
                else cout << "khong ton tai so can tim" << endl;
                break;
            }
            case 0:
            {
                stop = false;
                break;
            }
            default:
            {
                break;
            }
        }
    }
    return 0;
}