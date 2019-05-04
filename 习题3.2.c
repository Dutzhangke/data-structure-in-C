#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}node;

node * creat_list()
{
	node * head, * tail;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	tail = head;
	int num;
	scanf("%d", &num);
	while(num != -1)
	{
		node * p_new = (node*)malloc(sizeof(node));
		p_new->data = num;
		p_new->next = NULL;
		tail->next = p_new;
		tail = p_new;
		scanf("%d", &num);
	} 
	return head;
}

void print_lots(node * L, node * P)
{
	int count = 1;
	node * h1, * h2;
	h1 = L->next;
	h2 = P->next;
	for(;h2!=NULL;h2=h2->next)
	{
		while(count<h2->data)
		{
			h1 = h1->next;
			count++;
		}
		printf("%d ",h1->data);
	}
}

int main(void)
{
	printf("��������������L�е�Ԫ��:");
	node * L = creat_list();
	printf("��������������P�е�Ԫ��:");
	node * P = creat_list();
	printf("�����Ľ��Ϊ:");
	print_lots(L, P);
	return 0;
}
