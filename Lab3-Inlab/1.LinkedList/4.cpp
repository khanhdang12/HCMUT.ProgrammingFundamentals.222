#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int searchLinkedList(node* head, int key)
{
    if (head == nullptr)
    {
        return -1;
    }

    node * temp = head;

    int i = 0;
    while (temp != nullptr)
    {
        if (temp -> data == key)
        {
            return i;
        }
        i += 1;
        temp = temp -> next;
    }
    return -1;
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
  print(head);
  int m;
  cin>>m;
  cout<<searchLinkedList(head,m);
  return 0;
}
