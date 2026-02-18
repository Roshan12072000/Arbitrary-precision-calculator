#include "apc.h"
int List1(Dlist **head1,Dlist **tail1,int data);
int List2(Dlist **head2,Dlist **tail2,int data);
int init(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *str1,char *str2)
{
    int i = 0;
	
    while(str1[i] != '\0')
    {
        if(List1(head1,tail1,str1[i] - '0') == FAILURE)
            {
                return FAILURE;
            }
        i++;
    }
    i = 0;
     while(str2[i] != '\0')
    {
        if(List2(head2,tail2,str2[i] - '0') == FAILURE)
            {
                return FAILURE;
            } 
        i++;   
    }
    return SUCCESS;
}
int List1(Dlist **head1,Dlist **tail1,int data)
{
    Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    if(*head1 == NULL)
    {
        *head1 = *tail1 =  new;
        return  SUCCESS;
    }
    (*tail1)->next = new;
    new->prev = *tail1;
    *tail1 = new;
    return SUCCESS;
}
int List2(Dlist **head2,Dlist **tail2,int data)
{
     Dlist *new = (Dlist *)malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    if(*head2 == NULL)
    {
        *head2 = *tail2 =  new;
        return  SUCCESS;
    }
    (*tail2)->next = new;
    new->prev = *tail2;
    *tail2 = new;
    return SUCCESS;
}