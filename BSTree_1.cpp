#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

typedef Node *Tree;

Node *CreateNode(int init)
{
    Node *p = new Node;
    p->data = init;
    p->left = NULL;
    p->right = NULL;
    return p;
};

void CreateTree(Tree &root)
{
    root = NULL;
};

void DestroyTree(Tree &root)
{
    if (root)
    {
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
};

void AddNode(Tree &root, Node *node)
{
    if (root)
    {
        if (root->data == node->data)
            return;
        if (node->data < root->data)
            AddNode(root->left, node);
        else
            AddNode(root->right, node);
    }
    else
    {
        root = node;
    }
};

Node *FindNode(Tree root, int x)
{
    if (root)
    {
        if (root->data == x)
            return root;
        if (x < root->data)
            return FindNode(root->left, x);
        return FindNode(root->right, x);
    }
    return NULL;
};

void PrintTree(Tree root, int option)
{
    switch (option)
    {
    case 1:
    {
        if (root)
        {
            PrintTree(root->left, option);
            cout << root->data << " ";
            PrintTree(root->right, option);
        };
        break;
    };
    case 2:
    {
        if (root)
        {
            PrintTree(root->left, option);
            PrintTree(root->right, option);
            cout << root->data << " ";
        }
        break;
    };
    case 3:
    {
        if (root)
        {
            PrintTree(root->right, option);
            cout << root->data << " ";
            PrintTree(root->left, option);
        }
        break;
    };
    case 4:
    {
        if (root)
        {
            PrintTree(root->right, option);
            PrintTree(root->left, option);
            cout << root->data << " ";
        }
        break;
    };
    case 5:
    {
        if (root)
        {
            cout << root->data << " ";
            PrintTree(root->left, option);
            PrintTree(root->right, option);
        }
        break;
    };
    case 6:
    {
        if (root)
        {
            cout << root->data << " ";
            PrintTree(root->right, option);
            PrintTree(root->left, option);
        }
        break;
    };
    default: 
        cout << "Wrong option!" << endl;
        break;
    };
};

void NLR(Tree root)
{
    if (root)
    {
        // Xử lý nút gốc (root)
        NLR(root->left);
        NLR(root->right);
    }
};

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        // Xử lý nút gốc (root)
        LNR(root->right);
    }
};

void LRN(Tree root)
{
    if (root)
    {
        LRN(root->left);
        LRN(root->right);
        // Xử lý nút gốc (root)
    }
};

void FindAndReplace1(Tree &p, Tree &tree)
{
    if (tree->left)
        FindAndReplace1(p, tree->left);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->right;
    }
};

void FindAndReplace2(Tree &p, Tree &tree)
{
    if (tree->right)
        FindAndReplace2(p, tree->right);
    else
    {
        p->data = tree->data;
        p = tree;
        tree = tree->left;
    }
};

void DeleteNode(Tree &root, int x)
{
    if (root)
    {
        if (x > root->data)
            DeleteNode(root->right, x);
        else if (x < root->data)
            DeleteNode(root->left, x);
        else
        {
            Node *p = root;
            if (!root->left)
                root = root->right;
            else if (!root->right)
                root = root->left;
            else
                FindAndReplace1(p, root->right);
            // FindAndReplace2(p, root->left);
            delete p;
        }
    }
    else
    {
        cout << "Not found!\n";
    }
};

int main(){
    Tree root;
    int x;

    CreateTree(root);

    do{
        cin >> x;
        if (x == 0) break;
        Node* node = CreateNode(x);
        AddNode(root, node);
    } while (true);

    cout << "LNR: "; PrintTree(root, 1); cout << endl;
    cout << "LRN: "; PrintTree(root, 2); cout << endl;
    cout << "RNL: "; PrintTree(root, 3); cout << endl;
    cout << "RLN: "; PrintTree(root, 4); cout << endl;
    cout << "NLR: "; PrintTree(root, 5); cout << endl;
    cout << "NRL: "; PrintTree(root, 6); cout << endl;

    return 0;
}
