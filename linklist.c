#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node * next;
}node;

node * creat_list();
void traverse_list(node*head);
int is_empty(node * head);
void delete_node(node* head, int val);
void insert_node(node * head, int position, int val);

int main(void)
{
	node * head = NULL;
	head = creat_list();
	if(is_empty(head))
	{
		printf("����Ϊ��\n"); 
	}else
	{
		printf("����ǿ�\n"); 
	} 
	traverse_list(head);
	delete_node(head, 3);
	traverse_list(head);
	insert_node(head, 3, 0);
	traverse_list(head);
	return 0;
}

node * creat_list()
{
	node * head = (node*)malloc(sizeof(node));
	node * p_new = NULL;
	node * p_tail = head;
	int i;
	for(i=1;i<=5;i++)
	{
		p_new = (node*)malloc(sizeof(node));
		p_new->data = i;
		p_new->next = NULL;
		p_tail->next = p_new;
		p_tail = p_new;
	}
	return head;
}

void traverse_list(node*head)
{
	node * p = head->next;
	if(head != NULL)
	{
		do
		{
			printf("%d ", p->data);
			p = p->next;
		}while(p != NULL);
	}
	printf("\n");
}

int is_empty(node * head)
{
	return head->next == NULL;
}

void delete_node(node*head, int val)
{
	node * p1 = head->next;
	node * p2 = NULL;
	node * t =NULL;
	while(p1->data != val && p1->next != NULL)
	{
		p2 =p1;
		p1 = p1->next;
	}
	if(p1->data == val)
	{
		t = p1;
		p2->next = p1->next;
		free(t);
		t = NULL;
		printf("�ڵ�ɾ���ɹ�!\n");	
	}else
	{
		printf("�ýڵ㲻����!\n"); 
	}
}

void insert_node(node* head, int position, int val)
{
	int cnt = 0;//ͳ�ƽڵ���� 
	node * p = (node*)malloc(sizeof(node));//����һ��������ڵ� 
	p->data = val;
	p->next = NULL;
	
	node * p1 = head;//�������� 
	node * p2 = NULL;
	while(cnt != position && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		cnt++;
	}
	
	if(cnt == position)//�ж����� 
	{
		p2->next = p;
		p->next = p1;
		printf("����ڵ�ɹ�!\n");
	}else
	{
		printf("Out of space!\n");
	}
} 















