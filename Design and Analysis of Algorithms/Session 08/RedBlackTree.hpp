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
};