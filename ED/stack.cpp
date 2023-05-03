/*
Aula de Estruturas de Dados ministrada por Rafael Pinho
03/05/2023
*/

#include <iostream>

using namespace std;

struct Node
{
    int iData;
    struct Node* ptrNextNode;
};

struct Node* ptrTopNode = nullptr;

void display()
{
    struct Node* ptrNode = nullptr;
    
    if (ptrTopNode == nullptr) cout << "Pilha está vazia!" << endl;
    else
    {
        ptrNode = ptrTopNode;
        cout << "Elementos na Pilha: ";
        
        while(ptrNode != nullptr)
        {
            cout << ptrNode->iData << " ";
            ptrNode = ptrNode->ptrNextNode;
        }
        
        cout << endl;
    }
}

void push(int iVal)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iData = iVal;
    newNode->ptrNextNode = ptrTopNode;
    ptrTopNode = newNode;
}

void pop()
{
    if (ptrTopNode == nullptr) cout << "Nada removido, pilha está vazia!" << endl;
    else
    {
        cout << "Elemento Removido: " << ptrTopNode->iData << endl;
        
        struct Node* tmpPTR = ptrTopNode;
        ptrTopNode = ptrTopNode->ptrNextNode;
        free(tmpPTR);
    }
}

int main()
{
    display();
    cout << "=======================" << endl;
    
    push(7);
    push(42);
    push(666);
    
    display();
    cout << "=======================" << endl;
    
    pop();
    pop();
    
    display();
    cout << "=======================" << endl;
    pop();
    display();
    cout << "=======================" << endl;
    pop();
    display();
    cout << "=======================" << endl;

    return 0;
}
