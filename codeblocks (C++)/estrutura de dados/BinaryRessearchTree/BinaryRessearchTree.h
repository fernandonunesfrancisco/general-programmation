#ifndef BINARYRESSEARCHTREE_H_INCLUDED
#define BINARYRESSEARCHTREE_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T element;
    Node<T> *subTreeLeft;
    Node<T> *subTreeRight;
};

template<typename T>
struct BinaryRessearchTree{
    int cardinality;
    Node<T>* root;
};

template<typename T>
void create(BinaryRessearchTree<T> &tree)
{
    tree.cardinality=0;
    tree.root=NULL;
}

template<typename T>
void destroyTree(Node<T>* &root)
{
    if(root!=NULL)
    {
        destroyTree(root->subTreeLeft);
        destroyTree(root->subTreeRight);
        delete(root);
    }
}

template<typename T>
void destroy(BinaryRessearchTree<T> &tree)
{
    destroyTree(tree.root);
    tree.cardinality=0;
}

template<typename T>
bool isEmpty(BinaryRessearchTree<T> &tree)
{
    return(tree.root==NULL);
}

template<typename T>
int size(BinaryRessearchTree<T> tree)
{
    return tree.cardinality;
}

template<typename T>
bool ressearch(Node<T> *root, T value)
{
    if(root==NULL)
        return false;
    if(value==root->element)
        return true;
    if(value<root->element)
        return(ressearch(root->subTreeLeft, value));
    else
        return(ressearch(root->subTreeRight, value));
}

template<typename T>
bool contains(BinaryRessearchTree<T> tree, T value)
{
    return(ressearch(tree.root, value));
}

template<typename T>
void insertNode(Node<T>* &root, T value)
{
    if(root==NULL){
        root=new Node<T>;

        root->element=value;
        root->subTreeLeft=NULL;
        root->subTreeRight=NULL;
    }
    else
    {
        if(value<root->element)
        {
            insertNode(root->subTreeLeft, value);
        }
        else{
            insertNode(root->subTreeRight, value);
        }
    }
}

template<typename T>
void insert(BinaryRessearchTree<T> &tree, T value)
{
    insertNode(tree.root, value);
    tree.cardinality++;
}

template<typename T>
Node<T>* removeLargest(Node<T>* &root)
{
    if(root->subTreeRight == NULL)
    {
        Node<T>* aux = root;
        root = root->subTreeLeft;
        return aux;
    }

    return removeLargest(root->subTreeRight);
}

template<typename T>
void removeNode(Node<T>* &root, T value)
{
    if(root != NULL)
    {
        if(value < root->element)
        {
            removeNode(root->subTreeLeft, value);
        }
        else
        {
            if(value > root->element)
            {
                removeNode(root->subTreeRight, value);
            }
            else
            {
                Node<T>* aux = root;

                if(root->subTreeLeft == NULL)
                {
                    root = root->subTreeRight;
                    delete(aux);
                }
                else
                {
                    if(root->subTreeRight == NULL)
                    {
                        root = root->subTreeLeft;
                        delete(aux);
                    }
                    else
                    {
                        aux = removeLargest(root->subTreeLeft);

                        root->element = aux->element;

                        delete(aux);
                    }
                }
            }
        }
    }
}

template<typename T>
void remove(BinaryRessearchTree<T> &tree, T value)
{
    if(contains(tree, value))
    {
        removeNode(tree.root, value);
        tree.cardinality--;
    }
}

template<typename T>
void showInOrder(Node<T>* root)
{
    if(root != NULL)
    {
        showInOrder(root->subTreeLeft);

        cout << root->element << " ";

        showInOrder(root->subTreeRight);
    }
}

template<typename T>
void show(BinaryRessearchTree<T> tree)
{
    showInOrder(tree.root);
}

template<typename T>
int heightRecursive(Node<T>* node)
{
    int n=0;
    if(node == NULL)
        return n;

    int leftHeight = heightRecursive(node->subTreeLeft);
    int rightHeight = heightRecursive(node->subTreeRight);

    if(leftHeight>rightHeight) n=leftHeight;
    else n=rightHeight;

    return 1 + n;
}

template<typename T>
int height(BinaryRessearchTree<T>& tree)
{
    return heightRecursive(tree.root);
}

#endif // BINARYRESSEARCHTREE_H_INCLUDED
