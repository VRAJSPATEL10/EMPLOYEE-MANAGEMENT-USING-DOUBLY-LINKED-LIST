#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{	
	int employee_id;
	long int salary,mobile_no;
	char name[20],mail[15],designation[15],birthdate[10];
	struct node *next,*prev;
}*head=NULL,*last,*ptr;

void menu();
void display();
void create();
void sort();
int update();
void search();
int searchbyemployee_id();
int searchbyname();
int searchbydesignation();
int del();

void main()
{
	char name[10],ans;
	int choice;
	printf("**************                                EMPLOYEE MANAGEMENT SYSTEM                          ********************");
	printf("\n\nWHAT IS YOUR NAME?\n");
	fflush(stdin);
	gets(name);
	printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME %s   !!!!!!!!!!!!!!!!!!!!!",name);
	printf("\n\n\nLET'S CREATE EMPLOYEE MANAGEMENT SYSTEM %s  \n\n",name);
	sleep(3);
	do
	{
		menu();
		printf("\n\nDO YOU WANT TO GO TO MAIN MENU?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


void menu()
{
	int choice;
	system("cls");
	printf("**************                                EMPLOYEE MANAGEMENT SYSTEM                          ********************");
	printf("\n\n\n\n1) DISPLAY EMPLOYEE'S LIST\n2) INSERT NEW EMPLOYEE DETAILS\n3) UPDATE EMPLOYEE DETAILS\n4) SEARCH EMPLOYEE DATA\n5) DELETE EMPLOYEE\n");
	printf("\nENTER YOUR CHOICE:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:display();
	       break;
		case 2:create();
		       sort();
			   break;
		case 3:update();
			   break;
		case 4:search();
			   break;
		case 5:del();
			   break;
		default:printf("\nNO PROPER INPUT GIVEN..\n");
	}
}


void display()
{
	system("cls");
	printf("**************                                ALL EMPLOYEE'S LIST                          ********************");
	if(head==NULL)
	{
		printf("\n\nNO RECORD!!");
	}
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n\nEMPLOYEE ID  ::\t%d",ptr->employee_id);
		printf("\nNAME         ::\t%s",ptr->name);
		printf("\nMOBILE NUMBER::\t+91-%ld",ptr->mobile_no);
		printf("\nE-MAIL       ::\t%s",ptr->mail);
		printf("\nDESIGNATION  ::\t%s",ptr->designation);
		printf("\nSALARY       ::\t%ld",ptr->salary);
		printf("\nBIRTHDATE    ::\t%s",ptr->birthdate);
		ptr=ptr->next;
	}
}


void create()
{
	system("cls");
    int employee_id;
	long int salary,mobile_no;
	char name[20],mail[15],designation[15],birthdate[10],ans;
	struct node *temp,*last;

	do
	{
		system("cls");
		printf("**************                                CREATE RECORD                          ********************");
		printf("\n\nENTER EMPLOYEE_ID          :");
		scanf("%d",&employee_id);
		printf("ENTER NAME                 :");
		fflush(stdin);
		gets(name);
		printf("ENTER MOBILE NUMBER        :");
		scanf("%ld",&mobile_no);
		printf("ENTER E-MAIL               :");
		fflush(stdin);
		gets(mail);
	    printf("ENTER DESIGNATION          :");
	    fflush(stdin);
		gets(designation);
		printf("ENTER SALARY               :");
		scanf("%ld",&salary);
		printf("ENTER BIRTHDATE[DD-MM-YYYY]:");
		fflush(stdin);
		gets(birthdate);
		while(strlen(birthdate)!=10)
		{		
			printf("ENTER VALID BIRTHDATE[DD-MM-YYYY]:");
			fflush(stdin);
			gets(birthdate);
		}
		temp=(struct node *)malloc(sizeof(struct node));
		if(head==NULL)
		{
			head=temp;
			temp->employee_id=employee_id;
			strcpy(temp->name,name);
			temp->mobile_no=mobile_no;
			strcpy(temp->mail,mail);
			strcpy(temp->designation,designation);
			temp->salary=salary;
			strcpy(temp->birthdate,birthdate);
			head->prev=NULL;
			head->next=NULL;
			last=head;
    	}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
		    temp->employee_id=employee_id;
			strcpy(temp->name,name);
			temp->mobile_no=mobile_no;
			strcpy(temp->mail,mail);
			strcpy(temp->designation,designation);
			temp->salary=salary;
			strcpy(temp->birthdate,birthdate);
			temp->prev=last;
			temp->next=NULL;
			last->next=temp;
			last=temp;
		}
		sort();
		printf("\nDO YOU WANT TO CONTINUE INSERTING A NEW RECORD?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


void sort()
{
	struct node *i,*j;
	int temp;
	int employee_id;
	long int salary,mobile_no;
	char name[20],mail[15],designation[15],birthdate[10];
	for(i=head;i->next!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->employee_id>j->employee_id)
			{
				employee_id=i->employee_id;
				i->employee_id=j->employee_id;
				j->employee_id=employee_id;
				strcpy(name,i->name);
				strcpy(i->name,j->name);
				strcpy(j->name,name);
				mobile_no=i->mobile_no;
				i->mobile_no=j->mobile_no;
				j->mobile_no=mobile_no;
				strcpy(mail,i->mail);
				strcpy(i->mail,j->mail);
				strcpy(j->mail,mail);
				strcpy(designation,i->designation);
				strcpy(i->designation,j->designation);
				strcpy(j->designation,designation);
				salary=i->salary;
				i->salary=j->salary;
				j->salary=salary;
				strcpy(birthdate,i->birthdate);
				strcpy(i->birthdate,j->birthdate);
				strcpy(j->birthdate,birthdate);
            }
        }
    }
}


int update()
{
	int employee_id,i;
	long int salary,mobile_no;
	char name[20],mail[15],designation[15],birthdate[10],ans;
	int c;
	system("cls");
	display();
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO RECORD!!");
		return 0;
	}
	printf("\n\nENTER THE EMPLOYEE ID WHOSE DETAILS YOU WANT TO UPDATE:");
	scanf("%d",&i);
	while(ptr!=NULL)
	{
		if(i==ptr->employee_id)
		{
			do
			{
				printf("\nWHAT DO YOU WANT TO UPDATE?\n1.EMPLOYEE ID\n2.NAME\n3.MOBILE NUMBER\n4.EMAIL\n5.DESIGNATION\n6.SALARY\n7.BIRTHDATE");
				printf("\nENTER YOUR CHOICE:");
				scanf("%d",&c);
				switch(c)
				{
					case 1:printf("\nENTER NEW EMPLOYEE ID:");
					       scanf("%d",&employee_id);
					       ptr->employee_id=employee_id;
					       sort();
						   break;
					case 2:printf("\nENTER NEW NAME:");
					       fflush(stdin);
					       gets(name);
					       strcpy(ptr->name,name);
						   break;
					case 3:printf("\nENTER NEW MOBILE NUMBER:");
					       scanf("%ld",&mobile_no);
						   ptr->mobile_no=mobile_no;
						   break;
					case 4:printf("\nENTER NEW E-MAIL:");
					       fflush(stdin);
					       gets(mail);
						   strcpy(ptr->mail,mail);
						   break;
					case 5:printf("\nENTER NEW DESIGNATION:");
					       fflush(stdin);
					       gets(designation);
						   strcpy(ptr->designation,designation);
						   break;
					case 6:printf("\nENTER NEW SALARY:");
					       scanf("%ld",&salary);
						   ptr->salary=salary;
						   break;
					case 7:printf("\nENTER NEW BIRTHDATE[DD-MM-YYYY]:");
					       fflush(stdin);
					       gets(birthdate);
						   while(strlen(birthdate)!=10)
						   {		
						   		printf("ENTER VALID BIRTHDATE[DD-MM-YYYY]:");
						   		fflush(stdin);
								gets(birthdate);
						   }
						   break;
				}
				printf("\nEMPLOYEE RECORD UPDATED SUCCESSFULLY.");
				sleep(2);
				printf("\r                                     ");
				printf("\nDO YOU WANT TO CONTINUE UPDATING?[y/n]:");
				fflush(stdin);
				scanf("%c",&ans);
				if(ans=='n')
				{
					return 0;
				}
			}while(ans=='y');
        }
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED EMPLOYEE NAME NOT FOUND!!");
	}
}


void search()
{
	char ans;
	int a;
	do
	{
		system("cls");
		printf("**************                                SEARCH EMPLOYEE DETAILS                          ********************");
		printf("\n\n1.SEARCH BY EMPLOYEE ID\n2.SEARCH BY NAME\n3.SEARCH BY DESIGNATION");
		printf("\nENTER YOUR CHOICE:");
		scanf("%d",&a);
		switch(a)
		{
			case 1:searchbyemployee_id();
				   break;
			case 2:searchbyname();
				   break;
			case 3:searchbydesignation();
				   break;
			default:printf("\nNO PROPER INPUT GIVEN.....\n");
		}
		printf("\n\nDO YOU WANT TO CONTINUE SEARCHING?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
}


int searchbyemployee_id()
{
	int e_id;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO RECORD!!");
		return 0;
	}
	printf("\nENTER THE EMPLOYEE ID TO BE SEARCHED:");
	scanf("%d",&e_id);
	while(ptr!=NULL)
	{
		if(e_id==ptr->employee_id)
		{
			printf("EMPLOYEE ID FOUND");
			sleep(2);
			printf("\r                 ");
			printf("\nEMPLOYEE DETAILS ARE BELOW:\n");
			printf("\n\nEMPLOYEE ID  ::\t%d",ptr->employee_id);
			printf("\nNAME         ::\t%s",ptr->name);
			printf("\nMOBILE NUMBER::\t+91-%ld",ptr->mobile_no);
			printf("\nE-MAIL       ::\t%s",ptr->mail);
			printf("\nDESIGNATION  ::\t%s",ptr->designation);
			printf("\nSALARY       ::\t%ld",ptr->salary);
			printf("\nBIRTHDATE    ::\t%s",ptr->birthdate);
			break;
		}
		ptr=ptr->next;
	}
	if(ptr==NULL)
	{
		printf("\n\nSEARCHED EMPLOYEE ID NOT FOUND IN RECORDS!!");
	}
}


int searchbyname()
{
	char name[20];
	int c=0;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO RECORD!!");
		c++;
		return 0;
	}
	printf("\nENTER THE NAME OF EMPLOYEE TO BE SEARCHED:");
	fflush(stdin);
	gets(name);
	while(ptr!=NULL)
	{
		if(strcmp(name,ptr->name)==0)
		{
			printf("EMPLOYEE NAME FOUND");
			sleep(2);
			printf("\r                   ");
			printf("\nEMPLOYEE DETAILS ARE BELOW:\n");
			printf("\n\nEMPLOYEE ID  ::\t%d",ptr->employee_id);
			printf("\nNAME         ::\t%s",ptr->name);
			printf("\nMOBILE NUMBER::\t+91-%ld",ptr->mobile_no);
			printf("\nE-MAIL       ::\t%s",ptr->mail);
			printf("\nDESIGNATION  ::\t%s",ptr->designation);
			printf("\nSALARY       ::\t%ld",ptr->salary);
			printf("\nBIRTHDATE    ::\t%s",ptr->birthdate);
			c++;
		}
		ptr=ptr->next;
	}
	if(c==0)
	{
		printf("\n\nSEARCHED EMPLOYEE NAME NOT FOUND IN RECORDS!!");
	}
}


int searchbydesignation()
{
	int c;
	char designation[15];
	ptr=head;
	if(ptr==NULL)
	{
		printf("\n\nNO RECORD!!");
		c++;
		return 0;
	}
	printf("\nENTER THE DESIGNATION OF EMPLOYEE TO BE SEARCHED:");
	fflush(stdin);
	gets(designation);
	while(ptr!=NULL)
	{
		if(strcmp(designation,ptr->designation)==0)
		{
			printf("EMPLOYEE DESIGNATION FOUND");
			sleep(2);
			printf("\r                          ");
			printf("\nEMPLOYEE DETAILS ARE BELOW:\n");
			printf("\n\nEMPLOYEE ID  ::\t%d",ptr->employee_id);
			printf("\nNAME         ::\t%s",ptr->name);
			printf("\nMOBILE NUMBER::\t+91-%ld",ptr->mobile_no);
			printf("\nE-MAIL       ::\t%s",ptr->mail);
			printf("\nDESIGNATION  ::\t%s",ptr->designation);
			printf("\nSALARY       ::\t%ld",ptr->salary);
			printf("\nBIRTHDATE    ::\t%s",ptr->birthdate);
			c++;
		}
		ptr=ptr->next;
	}
	if(c==0)
	{
		printf("\n\nSEARCHED EMPLOYEE NAME NOT FOUND IN RECORDS!!");
	}
}


int del()
{
	int c=0,e_id;
	ptr=head;
	system("cls");
	printf("**************                                DELETE RECORD                         ********************");
	if(ptr==NULL)
	{
		printf("\n\nNO RECORD FOUND!!");
		return 0;
	}
	printf("\n\nENTER EMPLOYEE ID TO DELETE:");
	scanf("%d",&e_id);
	while(ptr!=NULL)
	{
		if(e_id==ptr->employee_id)
		{
			c=1;
			break;
		}
		else
		{
			c=2;
		}
		ptr=ptr->next;
	}
	if(c==1 && ptr!=head && ptr->next!=NULL)
	{
		ptr->prev->next=ptr->next;
		ptr->next->prev=ptr->prev;
		free(ptr);
		printf("\nYOUR RECORD IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(ptr==head)
	{
		if(head->next==NULL)
		{
			head=NULL;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
		}
		free(ptr);
		printf("\nYOUR CONTACT IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(ptr->next==NULL)
	{
		ptr->prev->next=NULL;
		ptr->prev=NULL;
		free(ptr);
		printf("\nYOUR CONTACT IS SUCCESSFULLY DELETED.");
		sleep(2);
		printf("\r                                     ");
	}
	else if(c==2)
	{
		printf("\nTHE EMPLOYEE ID YOU ENTERED IS NOT IN THE RECORD!!");
	}
}
