struct node
{
int data;
node * next;
};

void removeNode(node *head, int value) { //node not in first position
    node *temp;
    node *prev;
    node *head1;
    head1 = head;
    temp = head1;
    while(temp!=NULL) {
        if(temp->data == value) {
            prev->next = temp->next;
            break;
        }
       prev = temp;
       temp = temp->next;
   }
}
