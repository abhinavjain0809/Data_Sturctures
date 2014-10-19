#include <iostream>
#include <cstdlib>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
using namespace std;

typedef struct node{
	int data;
	struct node *next;
	struct node *child;
}N;

N *createList(int *arr, int n)
{
    N *head = NULL;
    N *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct node *)malloc(sizeof(*p));
        else {
            p->next = (struct node *)malloc(sizeof(*p));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}

N *createList(void)
{
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
 
    /* create 8 linked lists */
    N *head1 = createList(arr1, SIZE(arr1));
    N *head2 = createList(arr2, SIZE(arr2));
    N *head3 = createList(arr3, SIZE(arr3));
    N *head4 = createList(arr4, SIZE(arr4));
    N *head5 = createList(arr5, SIZE(arr5));
    N *head6 = createList(arr6, SIZE(arr6));
    N *head7 = createList(arr7, SIZE(arr7));
    N *head8 = createList(arr8, SIZE(arr8));
 
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;
 
 
    /* Return head pointer of first linked list.  Note that all nodes are
       reachable from head1 */
    return head1;
}

void display(N *start){
	N *ptr = start;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr = ptr->next;
	}
	cout<<endl;
}

N *flatten(N *head){
	N *end=head;
	while(end->next)	end = end->next;
	
	N *ptr=head;
	while(ptr){
		if(ptr->child){
			N *temp = ptr->child;
			ptr->child = NULL;
			end->next = temp;
			while(end->next)	end = end->next;
		}
		ptr = ptr->next;
	}
	return head;
}

int main(){
	N *head=NULL;
	head = createList();
	head = flatten(head);
	display(head);
	return 0;
}
