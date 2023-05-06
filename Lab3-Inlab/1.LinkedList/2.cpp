#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

node *insertNode(node *head, node *newNode, int position)
{
    if (position <= 0)
    {
        return head;
    }

    int count = 0;
    node * temp = head;
    while (temp != nullptr)
    {
        count += 1;
        temp = temp -> next;
    }

    if (position > count)
    {
        node * last = head;
        while (last -> next != nullptr)
        {
            last = last -> next;
        }
        last -> next = newNode;
    }

    else 
    {
        node * temp2 = head;
        for (int i = 0; i < position - 2; i++)
        {
            temp2 = temp2 -> next;
        }
        newNode -> next = temp2 -> next;
        temp2 -> next = newNode;
    }
    return head;
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  node *newNode = new node();
  cin >> newNode->data;
  int position = 0;
  cin >> position;
  head = insertNode(head, newNode, position);
  print(head);
  return 0;
}


