/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
int my_strlen(Dlist *temp);

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2,Dlist **tailR, Dlist **headR, char **argv,int detect)
{
	/* Definition goes here */
	char *str1 = argv[1], *str2 = argv[3];
	int flag = 0,i = 1,j = 1;
	if(detect == 0){
	int res = init(head1, tail1, head2, tail2, str1, str2);
	if (res == FAILURE)
	{
		return FAILURE;
	}
	}
	if (my_strlen(*head1) <= my_strlen(*head2))
	{	
		if(my_strlen(*head1) == my_strlen(*head2))
		{	
			if ((*head1)->data < (*head2)->data)
			{
			goto L1;
			}
			if ((*head1)->data > (*head2)->data)
			{
			goto M1;
			}
			Dlist *dummy1 = *head1,*dummy2 = *head2;
			while(dummy1 != NULL){
				if(dummy1->data < dummy2->data)
				{
					goto L1;
				}
				i++;
				dummy1 = dummy1->next;
				dummy2 = dummy2->next;
			}
		
		}

		else
		{
		L1:
			Dlist **temp = head1;
			head1 = head2;
			head2 = temp;
			temp = NULL;
			temp = tail1;
			tail1 = tail2;
			tail2 = temp;

			flag = 1;
		}
	}
M1 : if(detect == 0){
	printf(" ");
	print(*head1);
	printf("\n ");
	print(*head2);
	}
	Dlist *temp1 = *tail1, *temp2 = *tail2,*track = *head1;
	int sub = 0,carry = 0;
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1 != NULL && temp2 != NULL)
		{

			if (temp1->data < temp2->data)
			{
				temp1->data -= carry;
				carry = 0; 
				if((temp1->prev)->data == 0)
					{
						carry = 1;
						(temp1->prev)->data = 10;
					}
				((temp1->prev)->data)--;
				sub = temp1->data + 10 - temp2->data;
			}
			else
			{		
				if(flag == 1)
				{
					while(j < i){
						track = track->next;j++;
					}
					if(*head1 == temp1->prev && (*head1)->data - carry == 0)
					goto nextLine;
					if(track == temp1){
			nextLine : sub = temp1->data - temp2->data;
					sub *= -1;  //List3(headR, sub);
					insert_first(headR,tailR,sub);
					goto M;
					}
				}
				sub = temp1->data - temp2->data;
			}
			if (temp1->prev == NULL)
			{
				sub -= carry;
				if (flag == 1)
					sub = sub * -1;
			}
			//  List3(headR, sub);
			if(*head1 == temp1->prev && (*head1)->data - carry == 0){
				if(flag == 1)
				sub *= -1; 
				insert_first(headR,tailR,sub);goto M;
			}

				insert_first(headR,tailR,sub);
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else if (temp1 != NULL)
		{
			if(temp1->data != 9 && carry == 1)
			{
				(temp1->data)--;
				carry = 0;
			}
			if (temp1->prev == NULL)
			{
				temp1->data = temp1->data - carry;
				if (flag == 1){;
					temp1->data = temp1->data * -1;
				}
			}
			else if((temp1->prev)->data == 0 && carry == 1 )
			{
			
				(temp1->prev)->data = 9;
				carry = 1;
			}
			else if(temp1->prev != NULL && carry == 1 )
			{
				
				((temp1->prev)->data)--;
				carry = 0;
			}
			else if(temp1->data == 0 && carry == 1)
				{
					if(temp1->prev != 0)
					{
						((temp1->prev)->data)--;
						carry = 0;
					}
					else{
						temp1->data = 9;
						carry = 1;}
				}

			if((*head1)->data - carry == 0 || (*head1)->data == 0)
			{
			
				if(temp1 == (*head1)->next)
				{
					if (flag == 1){;
					temp1->data = temp1->data * -1;
				}
					//List3(headR, temp1->data);
						 insert_first(headR,tailR,temp1->data);
					break;
				}
			}
			//List3(headR, temp1->data);
				insert_first(headR,tailR,temp1->data);
			temp1 = temp1->prev;
		}
	}
	M :
	if(detect == 0){
	 printf("\n");
	print(*headR);
	}
	return SUCCESS;
}

int my_strlen(Dlist *temp)
{
	int n = 0;
	if(temp != NULL){
		n = 1;
	while(temp->next != NULL)
	{
		temp = temp->next;
		n++;
	}
	}
	return n;
}