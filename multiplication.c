/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int insert_first(Dlist  **ptr,Dlist **tail,int data)
{
	Dlist  *new = (Dlist *)malloc(sizeof(Dlist));
	if(new == NULL)
	{
		return FAILURE;
	}
	new->data = data;
	new->prev = NULL;
	new->next = *ptr;
	if(*ptr == NULL)
	{
		*tail = new;
	}
	else
	(*ptr)->prev = new;
	*ptr = new;
	return SUCCESS;
}

Dlist *R1 = NULL, *R2 = NULL,*R1tail = NULL,*R2tail = NULL;
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR, char **argv)
{
	/* Definition goes here */
	char *str1 = argv[1], *str2 = argv[3];
	int flag = 0, i = 0, j = 0;
	int res = init(head1, tail1, head2, tail2, str1, str2);
	if (res == FAILURE)
	{
		return FAILURE;
	}
	printf(" ");
	print(*head1);
	printf("X ");
	print(*head2);
	int len1 = calculate_length(*head1);
	int len2 = calculate_length(*head2);
	if(len1 < len2)
	{
			Dlist **temp = head1;
			head1 = head2;
			head2 = temp;
			temp = NULL;
			temp = tail1;
			tail1 = tail2;
			tail2 = temp;
	}
	int count = 0, carry = 0, mul = 0;
	Dlist *t2 = *tail2;
	while (t2 != NULL)
	{
		Dlist *t1 = *tail1;
		while (t1 != NULL)
		{
			mul = t2->data * t1->data + carry;
			carry = 0;
			if (mul > 9)
			{
				carry = mul / 10;
				mul = mul % 10;
				
			}
			if (flag == 1)
			{
				insert_first(&R2,&R2tail, mul);
			}
			else
				insert_first(&R1,&R1tail, mul);
			t1 = t1->prev;
		}
		if (carry != 0)
		{
			if (flag == 1)
			{
				insert_first(&R2,&R2tail,carry);
			}
			else
				insert_first(&R1,&R1tail, carry);
			carry = 0;
		}
		
		if(count >= 1)
		{
				for(i = 0; i < count; i++)
					List1(&R2,&R2tail, 0);	
		
			if(sum(R1tail, R2tail,headR,tailR) == FAILURE)
			return FAILURE;
			free(R2);
			R2 = R2tail = NULL;
			free(R1);
			R1 = *headR;R1tail = *tailR;
		} 
		flag = 1;
		count++;
		t2 = t2->prev;
	}
	printf("\n");
	print(R1);
	printf("\n");
	return SUCCESS;
}
