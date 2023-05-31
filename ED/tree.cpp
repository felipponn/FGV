// Aula de Introdução a árvores (árvore binária, tree traversal, e BST)
// Ministrada por Rafael Pinho em 31/05/23
#include <iostream>
using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

struct Node* newNode(int iData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->iPayload = iData;
    newNode->ptrRight = nullptr;
    newNode->ptrLeft = nullptr;
    
    return newNode;
}

void traversePreOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

void traversePostOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode->ptrLeft);
        traversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        traverseInOrder(ptrStartingNode->ptrRight);
    }
}

struct Node* searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr;
    if (node->iPayload == iData) return node;
    if (node->iPayload > iData) return searchNode(node->ptrLeft, iData);
    return searchNode(node->ptrRight, iData);
}

int main()
{
    struct Node* root = newNode(42);
    root->ptrLeft = newNode(7);
    root->ptrRight = newNode(666);
    root->ptrLeft->ptrLeft = newNode(1);
    root->ptrLeft->ptrRight = newNode(13);
    
    cout << "Atravessando a árvore - PreOrder:";
    traversePreOrder(root);
    cout << endl;
    
    cout << "Atravessando a árvore - InOrder:";
    traverseInOrder(root);
    cout << endl;
    
    cout << "Atravessando a árvore - PostOrder:";
    traversePostOrder(root);
    cout << endl;
    
    string resultado;
    
    resultado = (nullptr == searchNode(nullptr, 42))? "OK":"Deu Ruim";
    cout << "Busca nullptr: " << resultado << endl;
    
    resultado = (root == searchNode(root, 42))? "OK":"Deu Ruim";
    cout << "Busca 42: " << resultado << endl;
    
    resultado = (root->ptrLeft == searchNode(root, 7))? "OK":"Deu Ruim";
    cout << "Busca 7: " << resultado << endl;
    
    resultado = (root->ptrLeft->ptrLeft == searchNode(root, 1))? "OK":"Deu Ruim";
    cout << "Busca 1: " << resultado << endl;
    
    resultado = (nullptr == searchNode(root, 10))? "OK":"Deu Ruim";
    cout << "Busca Não-Existente: " << resultado << endl;

    return 0;
}
