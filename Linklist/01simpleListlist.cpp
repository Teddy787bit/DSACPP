#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class SimpleLinkList
{
private:
    Node *head, *tail;

public:
    SimpleLinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void InsertNodeatfront(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void InsertNode(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    void PrintList()
    {
        // Check for empty list.
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        while (head != NULL)
        {
            cout << head->data << endl;
            head = head->next;
        }
    }
    void InsertNodeatfront(){
        
    }
};
int main()
{
    SimpleLinkList list1;
    list1.InsertNode(60);
    list1.InsertNode(70);
    list1.InsertNode(80);
    list1.PrintList();
}