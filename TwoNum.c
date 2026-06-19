#include <stdio.h>
#include <stdlib.h>

struct listNode {

	int val;

	struct listNode *next; };


typedef struct listNode node;

node *addTwoNumbers(node *l1 , node *l2){

	node *dummyHead = malloc(sizeof(node));
	dummyHead->next = NULL;
	dummyHead->val = 0;
	node *temp = dummyHead;
	int carry = 0;
	while(l1!=NULL || l2!=NULL || carry != 0){

		int x=0,y=0;
	
		if(l1){
			x =  l1->val;
			l1 = l1->next;
			}
	       	if(l2){
			y = l2->val;
			l2 = l2->next;
		}

		int sum = x + y + carry;
		carry = sum / 10;
		temp -> next = malloc(sizeof(node));
		temp->next->val = sum % 10;
		temp->next->next = NULL;
		temp = temp ->next;
		}

	node *result = dummyHead->next;
	free(dummyHead);
	return result;	

	}


int main(){
	
	node *a = malloc(sizeof(node));
        node *b = malloc(sizeof(node));
        node *c = malloc(sizeof(node));

	a->val = 2;
	b->val = 4;
	c->val = 3;

	a->next = b;
	b->next = c;
	c->next = NULL;

	node *d = malloc(sizeof(node));
	node *e = malloc(sizeof(node));
	node *f = malloc(sizeof(node));

	d->val = 5;
	e->val = 6;
	f->val = 4;

	d->next = e;
	e->next = f;
	f->next = NULL;

	node *result = addTwoNumbers(a,d);
	node *head = result;
	
	while(result !=NULL){
		printf("%d", result->val);
		result = result ->next;
	}	

	printf("\n");

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);

	while(head != NULL){
   	 node *temp = head;
    	head = head->next;
    	free(temp);
        }


	return 0 ;
}

