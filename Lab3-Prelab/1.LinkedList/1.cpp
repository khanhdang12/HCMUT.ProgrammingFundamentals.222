#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

bool isEqual(node *head1, node *head2)
{
    node * temp1 = head1;
    node * temp2 = head2;

    int dem1 = 0;
    while (temp1 != nullptr)
    {
        dem1 += 1;
        temp1 = temp1 -> next;
    }

    int dem2 = 0;
    while (temp2 != nullptr)
    {
        dem2 += 1;
        temp2 = temp2 -> next;
    }

    if (dem1 != dem2)
    {
        return false;
    }

    temp1 = head1;
    temp2 = head2;

    while (temp1 != nullptr)
    {
        if (temp1 -> data != temp2 ->data)
        {
            return false;
        }
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return true;
}

int main()
{
  int n = 0;
  cin>> n;
  node *head1 = createLinkedList(n);
  int m = 0;
  cin>> m;
  node *head2 = createLinkedList(m);
  cout << isEqual(head1, head2) << endl;
  return 0;
}
