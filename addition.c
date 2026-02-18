/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int sum(Dlist *temp1,Dlist *temp2,Dlist **headR,Dlist **tailR)
{
	
	*headR = NULL,*tailR = NULL;
	int carry = 0, data = 0;
	while (temp2 != NULL || temp1 != NULL)
	{

		if (temp2 != NULL && temp1 != NULL)
		{
			data = temp1->data + temp2->data + carry;
			carry = 0;
			if (data > 9)
			{
				carry = data / 10;
				data = data % 10;
			}
			if (insert_first(headR,tailR, data) == FAILURE)
				return FAILURE;
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else if(temp2 != NULL)
		{
			if (insert_first(headR,tailR, temp2->data) == FAILURE)
				return FAILURE;	
			temp2 = temp2->prev;
		}
		else
		{
			if (insert_first(headR,tailR, temp1->data) == FAILURE)
				return FAILURE;	
			temp1 = temp1->prev;
		}
	
	}

	printf("\n");
	if (carry != 0)
	{
		if (insert_first(headR,tailR, carry) == FAILURE)
			return FAILURE;
		carry = 0;
	}
	else
		printf("  ");
		return SUCCESS;
}

int List3(Dlist **headR, int data);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,char **argv)
{
	/* Definition goes here */
	
	char *str1 = argv[1],*str2 = argv[3];
	int res = init(head1, tail1, head2, tail2, str1,str2);
	if (res == FAILURE)
	{
		return FAILURE;
	}
	printf("  ");
	print(*head1);
	printf("\n  ");
	print(*head2);

	//Dlist *temp1 = *tail1, *temp2 = *tail2;
	sum(*tail1,*tail2,headR,tailR);
	
	print(*headR);
	return SUCCESS;
}
void print(Dlist *head)
{
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}
int List3(Dlist **headR, int data)
{
	Dlist *new = (Dlist *)malloc(sizeof(Dlist));
	if (new == NULL)
	{
		return FAILURE;
	}
	new->data = data;
	new->next = *headR;
	*headR = new;
	return SUCCESS;
}
