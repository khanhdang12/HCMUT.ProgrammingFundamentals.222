#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    node * head = new node;
    head -> data = arr[0];

    for (int i = 1; i < n; i++)
    {
        node * temp = new node;
        node * last = head;
        temp -> data = arr[i];
        temp -> next = nullptr;
        while (last -> next != nullptr)
        {
            last = last -> next;
        }
        last -> next = temp;
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
  if (n > 0)
  {
    node *head = createLinkedList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }
  return 0;
}
