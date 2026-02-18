/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
            : tail1: Pointer to the last node of the first double linked list.
            : head2: Pointer to the first node of the second double linked list.
            : tail2: Pointer to the last node of the second double linked list.
            : headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
void flush(Dlist **clear);
int calculate_length(Dlist *head1);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, char **argv)
{
    Dlist *tailR = NULL;
    /* Definition goes here */
    char *str1 = argv[1], *str2 = argv[3];
    int res = init(head1, tail1, head2, tail2, str1, str2);
    if (res == FAILURE)
    {
        return FAILURE;
    }
    printf("  ");
    print(*head1);
    printf("\n  ");
    print(*head2);
    printf("\n  ");
    int count = 0;
    int len1 = 0, len2 = 0;

    len2 = calculate_length(*head2);

    len1 = calculate_length(*head1);
    while (len1 >= len2)
    {

        if (len1 == len2)
        {
            Dlist *temp1 = *head1, *temp2 = *head2;
            if ((*head1)->data == (*head2)->data)
            {
                while (temp1 != NULL)
                {
                    if (temp1->data < temp2->data)
                    {
                        goto Last;
                    }
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                subtraction(head1, tail1, head2, tail2, &tailR, headR, argv, 1);
                count++;
                break;
            }
            else if (temp1->data > temp2->data)
            {
                subtraction(head1, tail1, head2, tail2, &tailR, headR, argv, 1);
                count++;
                if(len1 == 1 && (*headR)->data == 0)
                {
                    goto Last;
                }
                flush(head1);
                *head1 = *tail1 = NULL;
                while (tailR != NULL)
                {
                    insert_first(head1, tail1, tailR->data);
                    tailR = tailR->prev;
                }
                flush(headR);
            *headR = tailR = NULL;
            }
            else
                break;
        }
        if (len1 > len2)
        {
            subtraction(head1, tail1, head2, tail2, &tailR, headR, argv, 1);
            
            count++;
            flush(head1);
            *head1 = *tail1 = NULL;
            while (tailR != NULL)
            {
                insert_first(head1, tail1, tailR->data);
                tailR = tailR->prev;
            }
            flush(headR);
            *headR = tailR = NULL;
           
        }
         len1 = calculate_length(*head1);
    }
Last:
    printf("Quotient is %d\n", count);
    return SUCCESS;
}
int calculate_length(Dlist *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

void flush(Dlist **clear)
{
    while (*clear != NULL)
    {
        Dlist *temp = *clear;
        *clear = (*clear)->next;
        free(temp);
    }
}
