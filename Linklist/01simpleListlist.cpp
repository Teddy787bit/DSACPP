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
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = newNode;
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
            cout << head->data << " -->";
            head = head->next;
        }
    }
    void InsertNodeatlast(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = head;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            return;
        }
    }
    void InsertNodeatpos(int pos, int data)
    {
        Node *prev, *curt, *newNode = new Node;
        newNode->data = data;
        curt = head;
        if (pos < 1)
        {
            cout << "Enter Valid Position" << endl;
        }
        else if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                prev = curt;
                curt = curt->next;
                if (curt == NULL)
                {
                    cout << "Invalid Position" << endl;
                    return;
                }
            }
            prev->next = newNode;
            newNode->next = curt;
        }
    }
    void SearchList(int data)
    {
        Node *curt = head;
        while (curt != NULL)
        {
            if (curt->data == data)
            {
                cout << "Element Found" << endl;
                return;
            }
            curt = curt->next;
        }
        cout << "Data not present in List" << endl;
    }
    void DeleteNode(int data)
    {
        bool Flag;
        Node *prv, *curt;
        prv = head;
        curt = head;
        while (curt != NULL)
        {
            if (curt->data == data && curt == head)
            {
                head = curt->next;
                free(curt);
                Flag = true;
                break;
            }
            else if (curt->data == data)
            {
                prv->next = curt->next;
                if (curt->next == tail)
                {
                    tail = prv;
                }
                free(curt);
                Flag = true;
                break;
            }
            prv = curt;
            curt = curt->next;
        }
        if (Flag == true)
        {
            cout << "Element Deleted" << endl;
        }
        else
        {
            cout << "Element Not found" << endl;
        }
    }
};
int main()
{
    SimpleLinkList list1;
    cout << "Simple/Single Link list initiated" << endl;
    bool x = true;
    while (x)
    {
        cout << "Welcome!!!\n Select from following option\n 1.Insert new Node at Start\n 2.Insert new Node at end \n 3.Search value in list \n 4.Delete Node from list \n 5.Display list \n 6.Exit" << endl;
        int n, data;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the elemnet value :- " << endl;
            cin >> data;
            list1.InsertNodeatfront(data);
            break;
        case 2:
            cout << "Enter the elemnet value :- " << endl;
            cin >> data;
            list1.InsertNodeatlast(data);
            break;
        case 3:
            cout << "Enter the value you want to search" << endl;
            cin >> data;
            list1.SearchList(data);
            break;
        case 4:
            cout << "Enter the value you want to delete" << endl;
            cin >> data;
            list1.DeleteNode(data);
            break;
        case 5:
            cout << "Elements in Link list is\n ---------- " << endl;
            list1.PrintList();
            cout << "\n --------- " << endl;
            break;
        case 6:
            x = false;
            break;
        default:
            cout << "Select right option" << endl;
            break;
        }
    }
}