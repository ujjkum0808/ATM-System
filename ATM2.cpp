#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*nw,*p,*m;

int w_amount,i,j,ch,t_amount,pass,coll,pass1,c=0,rem_bal,with[100],sum=0,rem,new_pass;
char name[100];
/*==============================================================================================================================================*/

int delay()
{
	int i,j;
	for(i=0;i<=34900;i++)
	{
		for(j=0;j<=34900;j++)
		{ }
	}
}
/*===============================================================================================================================================*/

int remain()
{
	rem=t_amount-sum;
	return 0;
}

/*================================================================================================================================================*/

int display()
{		
      p=head;
	  while(p!=NULL)
		{
			printf("%d ",p->data);
			p=p->next;
		}
		
	printf("\nTotal withdraw=%d",sum);
	remain();
	printf("\nRemaining Balance=%d",rem);
	
	return 0;
}

/*=========================================================================================================================================*/
/*=========================================================================================================================================*/

int change_passward()
{
	printf("\nEnter new passward:");
	scanf("%d",&new_pass);
	
	pass=new_pass;
	printf("Password Changed Successfully\n");
	printf("Your new passward is:%d",pass);
}
/*=========================================================================================================================================*/

int balance_enquiry()
{
	remain();
	printf("\nAvailable balance:%d",rem);
	return 0;
}

/*=========================================================================================================================================*/
/*=========================================================================================================================================*/

int insert_end(int x)
{
	nw=(struct node*)malloc(sizeof(struct node));
	nw->data=x;
	nw->next=NULL;
	
	p=head;
	if(p==NULL)
		head=nw;
	else
	{
		while(p->next !=NULL)
		{
		p=p->next;
	    }
	    p->next=nw;
	}
	return 0;
}
/*================================================================================================*/

int withdraw()
{
	
	printf("\nEnter passward:");
	scanf("%d",&pass1);
	
	if(pass1==pass)
	{
	printf("\nEnter Amount you want to withdraw:");
	scanf("%d",&w_amount);
	
	if(w_amount > t_amount)
	{
		printf("Insufficient Balance...");
	}
	else
	{
		sum=sum+w_amount;
		insert_end(w_amount);
		
		printf("\nTransition Proceed...");
		delay();
		
		printf("\nCollect Your Amount...\n");
		printf("press 1 to collect your Cash\npress 2 for cancel:");
		scanf("%d",&coll);
		
		switch(coll)
		{
			case 1:printf("Amount collected...\n");
				   printf("THANK YOU FOR USING THE ATM !!!\n");
				   break;
				   
			case 2: printf("\nTransition cancelled...");
					printf("THANK YOU FOR USING THE ATM !!!\n");
					exit(1);
					break;
		}		
	}
	}
	
	else
	{
		c++;
		printf("passward incorrect...\n");
		
		if(c==4)
		{
		printf("\nSorry for the inconvenence. your ATM card has been locked for 24 hours...");
		exit(1);
		}
		printf("Please try Again:\n");
		withdraw();
		
	}
	return 0;
}

/*==========================================================================================================================================*/
/*==========================================================================================================================================*/

int mini_statement()
{
	printf("\nYour mini statement\n");
	printf("preparing for ministatement...\n\n");
	
	delay();
	printf("Name:%s\n",name);
	printf("\n");
	printf("Your withdraw details\n");
	display();
	return 0;
}

/*==========================================================================================================================================*/
/*==========================================================================================================================================*/

int main()
{
	printf("Welcome to SBI\n");
	printf("Enter Your Details:\n");
	
	printf("Name:");
	scanf(" %[^\n]%*c",&name);
	
	printf("Four digit Passward:");
	scanf("%d",&pass);
	
	printf("Amount in Your Account:");
	scanf("%d",&t_amount);
	
	while(1)
	{
	printf("\npress 1 for withdraw\npress 2 for ministatement\npress 3 for passward change\npress 4 for balance enquiry\npress 5 for cancel:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:withdraw();
				break;
		case 2:mini_statement();
				break;
		case 3:change_passward();
				break;
	    case 4:balance_enquiry();
				break;
		case 5: printf("THANK YOU FOR USING THE ATM !!!\n");
				exit(1);
				break;
		default:printf("\nchoose a valid number...\n\n");
				
	}
	}
	
return 0;	
}

