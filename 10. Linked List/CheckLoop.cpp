//Question: Given a linked list, check if the linked list has loop or not.

#include <bits/stdc++.h>
using namespace std;
 
/* Link list Skeleton Code taken from gfg*/
struct Node {
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the data  */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
 
// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
  Node *fast_pointer = head;
  Node *slow_pointer = head;
  
  while(fast_pointer != NULL)
  {
    slow_pointer = slow_pointer->next;
    fast_pointer = fast_pointer->next->next;
    if(fast_pointer == slow_pointer)
    {
      return true;
    }
  }
  
  return false;
    
  
    }
 
    return false;
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
 
    return 0;
}
