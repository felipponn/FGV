#include <iostream>

using namespace std;

//Dever de Casa 1: Elaborar função auxiliar que cria um nó

struct Node
{
    int iData;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

void insertFront(struct Node** head, int iPayLoad)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iData = iPayLoad;
    newNode->ptrNext = (*head);
    newNode->ptrPrev = nullptr;
    
    if ((*head) != nullptr)
        (*head)->ptrPrev = newNode;
    
    (*head) = newNode;
}

void insertEnd(struct Node** head, int iPayLoad)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iData = iPayLoad;
    newNode->ptrNext = nullptr;
    
    if ((*head) == nullptr)
    {
        newNode->ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }
    
    struct Node* ptrTemp = (*head);
    
    while (ptrTemp->ptrNext != nullptr)
        ptrTemp = ptrTemp->ptrNext;
    
    newNode->ptrPrev = ptrTemp;
    ptrTemp->ptrNext = newNode;
}

void insertAfter(struct Node* ptrLocation, int iPayLoad)
{
    if (ptrLocation == nullptr)
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    }
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iData = iPayLoad;
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;
    
    ptrLocation->ptrNext = newNode;
    if (newNode->ptrNext == nullptr)
        return;
    newNode->ptrNext->ptrPrev = newNode;
}

void deleteFirst(struct Node** head)
{
    if ((*head) == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }
    
    struct Node* ptrTemp = (*head);
    
    (*head) = (*head)->ptrNext;
    if ((*head) != nullptr)
        (*head)->ptrPrev = nullptr;
    
    free(ptrTemp);
}

void deleteLast(struct Node** head)
{
    if ((*head) == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }
    
    struct Node* ptrTemp = (*head);
    
    while (ptrTemp->ptrNext != nullptr)
        ptrTemp = ptrTemp->ptrNext;
    
    if (ptrTemp->ptrPrev == nullptr)
        (*head) = nullptr;
    
    else
        ptrTemp->ptrPrev->ptrNext = nullptr;
    
    free(ptrTemp);
}

void deleteNode(struct Node** head, struct Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover o nó" << endl;
        return;
    }
    
    if (ptrDelete->ptrPrev == nullptr)
        *head = ptrDelete->ptrNext;
    
    else
        ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    
    if (ptrDelete->ptrNext != nullptr)
        ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    
    free(ptrDelete);
}

void displayList(struct Node* head)
{
    if (head == nullptr)
    {
        cout << "Não é possível exibir: lista vazia" << endl;
        return;
    }
    
    if (head->ptrPrev != nullptr)
    {
        cout << "Não é possível exibir: meio da Lista" << endl;
        return;
    }
    
    cout << "Payload: ";
    
    while (head != nullptr)
    {
        cout << head->iData << " ";
        head = head->ptrNext;
    }
    
    cout << endl;
}

int main()
{
    //Inicializando a lista
    struct Node* head = nullptr;
    displayList(head);
    cout << "====================" << endl;
    
    //Bloco de inserção
    insertAfter(head, -1);
    insertEnd(&head, 0);
    insertFront(&head, 1);
    insertEnd(&head, 7);
    insertFront(&head, 13);
    insertEnd(&head, 42);
    insertFront(&head, 666);
    
    displayList(head);
    cout << "====================" << endl;
    
    //Bloco de Remoção
    cout << "Deletando Head" << endl;
    deleteNode(&head, head);
    displayList(head);
    cout << "Deletando Head" << endl;
    deleteNode(&head, head);
    displayList(head);
    cout << "Deletando Meio" << endl;
    deleteNode(&head, head->ptrNext->ptrNext);
    displayList(head);
    cout << "====================" << endl;
    cout << "Deletando Fim" << endl;
    deleteNode(&head, head->ptrNext->ptrNext);
    displayList(head);
    cout << "====================" << endl;
    cout << "Deletando Além do Fim" << endl;
    deleteNode(&head, head->ptrNext->ptrNext);
    cout << "====================" << endl;
    
    insertAfter(head, 13);
    insertAfter(head->ptrNext, 42);
    insertAfter(head->ptrNext->ptrNext->ptrNext, 666);
    displayList(head);
    
    return 0;
}
