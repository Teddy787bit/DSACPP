#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(/* args */)
    {
        data = 0;
        next = NULL;
    }
};
class Listlist
{
private:
    Node *head, *tail;

public:
    Listlist()
    {
        head = NULL;
        tail = NULL;
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
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->data<<"-->";
            tmp = tmp->next;
        }
    }
};
int main()
{
    Listlist list1;
    list1.InsertNode(10);
    list1.InsertNode(30);
    list1.PrintList();
    return 0;
}