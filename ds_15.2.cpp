#include <iostream>
using namespace std;

/*
* 13.2
* Գրել ծրագիր, որը պղպջակի ալգորիթմով կարգավորում է միակապ ցուցակի տարրերը չնվազման կարգով։
*/

struct Node
{
    int data;
    Node* next;
};

Node* create_node(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

void display_list(Node* node)
{
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

Node* swap_nodes(Node* ptr1, Node* ptr2)
{
    Node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

void bubble_sort(Node** head, int count)
{
    Node** tmp;
    int i, j, swapped;

    for (i = 0; i < count - 1; i++)
    {
        tmp = head;
        swapped = 0;
        for (j = 0; j < count - i - 1; j++)
        {
            Node* ptr1 = *tmp;
            Node* ptr2 = ptr1->next;
            if (ptr1->data > ptr2->data)
            {
                *tmp = swap_nodes(ptr1, ptr2);
                swapped = 1;
            }

            tmp = &(*tmp)->next;
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    int t;
    cin >> t;

    if (t <= 0)
    {
        cout << "Invalid input for the number of elements.\n";
        return 1;
    }

    int arr[1000];

    for (int i = 0; i < t; i++)
        cin >> arr[i];

    Node* head = create_node(arr[0]);
    Node* tmp = head;

    for (int i = 1; i < t; i++)
    {
        tmp->next = create_node(arr[i]);
        tmp = tmp->next;
    }

    cout << "Original list\n";
    display_list(head);

    bubble_sort(&head, t);

    cout << "\nSorted linked list\n";
    display_list(head);

    return 0;
}
