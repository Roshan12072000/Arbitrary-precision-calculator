/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"
void validation (char *str1,char *str2);
int main(int argc, char *argv[])
{
	/* Declare the pointers */
	char *str1 = argv[1], *str2 = argv[3],*opr = argv[2];
	 if(argc == 1){
		printf("<./a.out> <operand> <'operation'> <operand>\n");
		exit(0);
	 }
	validation (str1,str2);
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char option, *operator;
	// int track = 0;
	/* Code for reading the inputs */

	/* Function for extracting the operator */
	operator= argv[2];

	switch (*operator)
	{
	case '+':
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv);
		/* call the function to perform the addition operation */
		break;
	case '-':
		subtraction(&head1, &tail1, &head2, &tail2, &tailR, &headR, argv, 0);
		/* call the function to perform the subtraction operation */
		break;
	case '*':
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR, argv);
		/* call the function to perform the multiplication operation */
		break;
	case '/':
	{
		if(str2[0] == '0')
		{
			printf("Enter 2nd operand non Zero value\n");
			return 0;
		}
		division(&head1, &tail1, &head2, &tail2, &headR, argv);
		/* call the function to perform the division operation */
		break;
	}
	default:
		printf("Invalid Input:-( Try again...\nEnter valid operator (such as)---> '+','-','*','/' \n");
	}

	return 0;
}
void validation (char *str1,char *str2)
{
	int i = 0;
	while (str1[i] != '\0')
	{
		if (isdigit(str1[i]) == 0)
		{
			printf("Enter a valid operands!!!\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		if (isdigit(str2[i]) == 0)
		{
			printf("Enter a valid operands!!!\n");
			exit(0);
		}
		i++;
	}
}