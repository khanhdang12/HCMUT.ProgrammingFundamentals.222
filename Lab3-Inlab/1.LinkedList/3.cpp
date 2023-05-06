#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

void replace(node* head, int position, int value)
{
    if (position < 0)
    {
        return;
    }

    node * temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        count += 1;
        temp = temp -> next;
    }

    if (position >= count)
    {
        return;
    }

    node * temp2 = head;
    for (int i = 0; i < position; i++)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> data = value;
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  int pos, val;
  cin>>pos>>val;
  replace(head, pos, val);
  print(head);
  return 0;
}
