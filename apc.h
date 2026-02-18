/*
Name : Roshan Jameer
id : 24018_029
 */
#ifndef APC_H
#define APC_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
 int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,char **argv);
 int init(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *str1,char *str2);
int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **tailR, Dlist **headR,char **argv,int detect);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,char **argv);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,char **argv);
void print(Dlist *head);
int List3(Dlist **headR, int data);
int List1(Dlist **head1,Dlist **tail1,int data);
int sum(Dlist *temp1,Dlist *temp2,Dlist **headR,Dlist **tailR);
int insert_first(Dlist  **ptr,Dlist **tail,int data);
int calculate_length(Dlist *head);
#endif
