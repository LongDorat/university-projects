#pragma once

#include <iostream>
#include <vector>

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int value;
    Color color;

    Node *parent;
    Node *left;
    Node *right;

    Node(int k) : value(k), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
};

class RedBlackTree
{
private:
    Node *root;
    Node *NIL;

    void leftRotation(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != NIL)
        {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == NIL)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotation(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;
        if (y->right != NIL)
        {
            y->right->parent = x;
        }

        y->parent = x->parent;
        if (x->parent == NIL)
        {
            root = y;
        }
        else if (x == x->parent->right)
        {
            x->parent->right = y;
        }
        else
        {
            x->parent->left = y;
        }
        
        y->right = x;
        x->parent = y;
    }

    void fixInsertion(Node *z)
    {
        while (z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *uncle = z->parent->parent->right;

                if (uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotation(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotation(z->parent->parent);
                }
            }
            else
            {
                Node *uncle = z->parent->parent->left;

                if (uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotation(z);
                    }

                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotation(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void transplant(Node *u, Node *v)
    {
        if (u->parent == NIL)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    Node* minimum(Node *x)
    {
        while (x->left != NIL)
        {
            x = x->left;
        }
        return x;
    }

    Node* search(int value)
    {
        Node* current = root;
        while (current != NIL && current->value != value)
        {
            current = (value < current->value) ? current->left : current->right;
        }
        return current;
    }

    void fixDelete(Node* x)
    {
        while (x != root && x->color == BLACK)
        {
            if (x == x->parent->left)
            {
                Node* sibling = x->parent->right;
                if (sibling->color == RED)
                {
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    leftRotation(x->parent);
                    sibling = x->parent->right;
                }
                if (sibling->left->color == BLACK && sibling->right->color == BLACK)
                {
                    sibling->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (sibling->right->color == BLACK)
                    {
                        sibling->left->color = BLACK;
                        sibling->color = RED;
                        rightRotation(sibling);
                        sibling = x->parent->right;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->right->color = BLACK;
                    leftRotation(x->parent);
                    x = root;
                }
            }
            else
            {
                Node* sibling = x->parent->left;
                if (sibling->color == RED)
                {
                    sibling->color = BLACK;
                    x->parent->color = RED;
                    rightRotation(x->parent);
                    sibling = x->parent->left;
                }
                if (sibling->right->color == BLACK && sibling->left->color == BLACK)
                {
                    sibling->color = RED;
                    x = x->parent;
                }
                else
                {
                    if (sibling->left->color == BLACK)
                    {
                        sibling->right->color = BLACK;
                        sibling->color = RED;
                        leftRotation(sibling);
                        sibling = x->parent->left;
                    }
                    sibling->color = x->parent->color;
                    x->parent->color = BLACK;
                    sibling->left->color = BLACK;
                    rightRotation(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

    void remove(Node* z)
    {
        Node* y = z;
        Color yOriginalColor = y->color;
        Node* x;

        if (z->left == NIL)
        {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == NIL)
        {
            x = z->left;
            transplant(z, z->left);
        }
        else
        {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z)
            {
                x->parent = y;
            }
            else
            {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (yOriginalColor == BLACK)
        {
            fixDelete(x);
        }
    }

    void printTree(Node* node, int  depth = 0, std::string prefix = "") const
    {
        if (node == NIL)
        {
            return;
        }

        printTree(node->right, depth + 1, "    " + prefix);
        std::cout << prefix << (node->color == RED ? "R" : "B") << ":" << node->value << std::endl;
        printTree(node->left, depth + 1, "    " + prefix);
    }

public:
    RedBlackTree()
    {
        NIL = new Node(0);
        NIL->color = BLACK;
        NIL->left = NIL->right = NIL->parent = NIL;
        root = NIL;
    }

    void insertValue(int value)
    {
        Node *z = new Node(value);
        z->left = z->right = NIL;

        Node *y = NIL;
        Node *x = root;
        while (x != NIL)
        {
            y = x;
            x = (value < x->value) ? x->left : x->right;
        }

        z->parent = y;
        if (y == NIL)
        {
            root = z;
        }
        else if (value < y->value)
        {
            y->left = z;
        }
        else
        {
            y->right = z;
        }
        z->color = RED;

        fixInsertion(z);
    }

    void deleteNode(int value)
    {
        Node* z = search(value);
        if (z != NIL)
        {
            remove(z);
        }
    }

    void print()
    {
        printTree(root);
        std::cout << "====================" << std::endl;
    }
};