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
    insertEnd(&head, 0);
    insertFront(&head, 1);
    insertEnd(&head, 7);
    insertFront(&head, 13);
    insertEnd(&head, 42);
    insertFront(&head, 666);
    
    displayList(head);
    cout << "====================" << endl;
    
    //Bloco de Remoção
    cout << "Deletando First" << endl;
    deleteFirst(&head);
    displayList(head);
    cout << "Deletando First" << endl;
    deleteFirst(&head);
    displayList(head);
    cout << "Deletando First" << endl;
    deleteFirst(&head);
    displayList(head);
    
    cout << "Deletando Last" << endl;
    deleteLast(&head);
    displayList(head);
    cout << "Deletando Last" << endl;
    deleteLast(&head);
    displayList(head);
    cout << "Deletando Last" << endl;
    deleteLast(&head);
    displayList(head);
    deleteFirst(&head);
    deleteLast(&head);
    cout << "====================" << endl;
    

    return 0;
}
