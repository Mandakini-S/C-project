#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void returnfunc();

void mainmenu();

void management();
void addrecord();
int getdata();
void deleterecord();
void searchrecord();
void viewrecord();

void customer();

void vegetarian();
void nonvegetarian();

void details();
void aboutus();

struct employee
{

	char name[30];
	int id;
	
	int dd; 
	int mm; 
	int yyyy;
	int YOJ;
	char place[20];
	float salary;
	char department[20];
	
	int quantity;
};
struct employee e;

FILE *fp,*ft;

int s;
char findrecord;
int again;
int quantity;
double total=0;
int t;

int main()
{
	mainmenu();
	return 0;
}


void mainmenu(void)
{
	system("cls");
	printf("                             \a    -------------------------------------------------------------------------\n\n\n");
	printf("                                                            WELCOME !!!\n\n");
	printf("                                         Feeling HUNGRY? Don't worry !! YUMMEEEE KITCHEN is here.' \n\n");
	printf("                                                          Lamachaur,WRC\n\n\n");
	printf("                                 -------------------------------------------------------------------------\n\n");
	
    time_t current_time;   // not a primitive datatype
    time(&current_time);

    printf("\n                                     ===>  Current Date and Time: %s \n ", ctime(&current_time));
	printf("          1. MANAGEMENT SECTION \n\n          2. MENU  \n\n          3. ABOUT US \n\n          4. Want to leave? \n\n\n             Enter Your Choice --->");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		management();
	}
	else if(choice==2)
	{
		customer();
	}
	else if(choice==3)
	{
		aboutus();
	}
	else if(choice==4)
	{
		system("cls");
		printf("\n\n\n");
		printf("  ---------------------THANK YOU   --------------------------------\n\a");

		printf("  ---------- Call or Walk-In to YUMMEEEE KITCHEN-------\n\n");
		exit(0);
	}
}

void management()
{

    system("cls");
	printf("--------------------------------WELCOME TO THE MANAGEMENT SECTION -------------------------------\n\n\a");
	printf("          1. Add New Record\n\n          2. Search Record\n\n          3. Delete Record\n\n          4. View THe Records\n\n              5. Back To Main Menu \n\n             Enter Your Choice --->");
	int n;
	scanf("%d",&n);
		printf("\n\n");
	

	if(n==1)
	{
		addrecord();
	}
	else if(n==2)
	{
		searchrecord();
	}
	else if(n==3)
	{
		deleterecord();
	}
	else if(n==4)
	{
		viewrecord();
	}
	else if(n==5)
	{
		system("cls");
		mainmenu();
	}
	else
	{
printf("Wrong Input !! PLease Re-enter The Correct Option\a");
	if(getch())
		management();
	}
	
}

void addrecord(void)
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getdata()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&e,sizeof(e),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("The Record Is Successfully Saved ! !\n\n\a");
		printf("Save any more?(Y / N): ");
		if(getch()=='n')
	    	management();
		else
	    	system("cls");
	    	addrecord();
	}	
}

void deleterecord(void)
{
	system("cls");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	printf("                Enter The Employee ID To Delete :\a");
	scanf(" %d",&d);
	fp=fopen("record1.txt","r+");
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	{
	    if(e.id==d)
	    {
			printf("\n\n");
			printf("                               .....................The Employee Record Is Available....................\n\n\a");
			printf("               Employee Name Is %s\n\n",e.name);
			printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			findrecord='t';
	    }
	}
	if(findrecord!='t')
	{
	    printf("                                    .........................No record is found modify the search..........................\n\n\a");
	    if(getch())
	    management();
	}
	if(findrecord=='t' )
	{
	    printf("Do You Want To Delete THe Record ? (Y/N)\a ");
	    if(getch()=='y')
	    {
			ft=fopen("test1.txt","w");  //temporary file for delete
			rewind(fp);
			while(fread(&e,sizeof(e),1,fp)==1)
			{
		    	if(e.id!=d)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&e,sizeof(e),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			remove("record1.txt");
			rename("test1.txt","record1.txt"); //copy all item from temporary file to fp except that
			fp=fopen("record1.txt","r");    //we want to delete
			if(findrecord=='t')
			{
		    	printf("        THE RECORD IS SUCCESSFULLY DELETED.\n\n\a");
		    	printf("        Delete Another Record ? (Y/N) : ");
			}
	    }
		else
		management();
		fflush(stdin); //to clear (or flush) the output buffer and move the buffered data
		               //to console (in case of stdout) or disk (in case of file output stream)
		another=getch();
	}
}
management();
}

void searchrecord(void)
{
	system("cls");
    int d;
    printf("                                  --------------------------------- Search Employees Record -------------------------------\n\n\a");
    printf("                  1. Search By ID\n");
    printf("                  2. Search By Name\n\n");
    printf("                  Enter Your Choice---> ");
    fp=fopen("record1.txt","r"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    switch(getch())
    {
	  case '1':
		{
	    	system("cls");
	    	printf("                                  ------------------------Search Record By Id--------------------------\n\n\a");
	    	printf("                Enter The Employee ID : ");
	    	scanf(" %d",&d);
	    	printf("\n\n");
			printf("Searching........");
	    	while(fread(&e,sizeof(e),1,fp)==1)
	    	{
				if(e.id==d)
				{
		    		printf("\n\n");
					printf("...........................The Record is available............................\n\n\a");
				    printf("       ID : %d\n\n",e.id);
				    printf("       Name : %s\n\n",e.name);
				    printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
				    printf("       Year Of Joining :%d\n\n",e.YOJ);
				    printf("       Department :%s\n\n",e.department);
				    printf("       Place :%s\n\n",e.place);
				    findrecord='t';
				}

	    }
	    if(findrecord!='t')  //checks whether conditiion enters inside loop or not
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (y/n)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    management();
	    break;
	}
	case '2':
	{
	    char s[15];
	    system("cls");
	    printf("                                   **********************Search Employees By Name***************************\n\n\a");
	    printf("               Enter Employee Name : ");
	    scanf(" %s",s);
	    int d=0;
	    while(fread(&e,sizeof(e),1,fp)==1)
	    {
		if(strcmp(e.name,(s))==0) //checks whether a.name is equal to s or not
		{
		    printf("                               .........................The Record is available...........................\n\n\n");
			printf("       ID : %d\n\n",e.id);
			printf("       Name : %s\n\n",e.name);
			printf("       Date OF Birth :%d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			printf("       Year Of Joining :%d\n\n",e.YOJ);
			printf("       Department :%s\n\n",e.department);
			printf("       Place :%s\n\n",e.place);
		    d++;
		}

	    }
	    if(d==0)
	    {
	    	printf("\aNo Record Found\a");
	    }
	    printf("Try Another Search ? (Y/N)");
	    if(getch()=='y')
	    searchrecord();
	    else
	    management();
	    break;
	}
	default :
	getch();
	searchrecord();
    }
    fclose(fp);
}

void viewrecord(void) 
{
    system("cls");
    printf("                              ********************** Employee Details**********************\n\n");
    printf("                 DEPARTMENT           ID      EMPLOYEE NAME             D.O.B          Y.O.J         PLACE\n\n");
    
    fp=fopen("record1.txt","r");
    while(fread(&e,sizeof(e),1,fp)==1)
    {
		printf("                 %s",e.department);
		printf("        %d",e.id);
		printf("        %s",e.name);
		printf("        %d/%d/%d",e.dd,e.mm,e.yyyy);
		printf("        %d",e.YOJ);
		printf("        %s",e.place);
		printf("\n\n");
	}
      
      fclose(fp);
      returnfunc();
}

void returnfunc(void)
{
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    management();
    else
    goto e;
}

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
	if(e.id==c)
	
	return 0;  //returns 0 if employee exits
    
	return 1; //return 1 if it not
}
int getdata()
{
	//*int t;
	printf("        Employee ID :\t");
	scanf("%d",&t);
	if(checkid(t)==0)
	{
		printf("\n\n");
		printf("\a                        The Employee Record Already Exists !!!\a");
		getch();
		mainmenu();
		return 0;
	}
	e.id=t;
	printf("        Employee Name : ");
	scanf("%s",e.name);
	printf("        Date Of Birth (dd/mm/yyyy) :");
	scanf("%d/%d/%d",&e.dd,&e.mm,&e.yyyy);
	printf("        Year OF Joining :");
	scanf("%d",&e.YOJ);
	printf("        Place :");
	scanf("%s",e.place);
	printf("        Department :");
	scanf("%s",e.department);
	return 1;
}
void customer(void)
{

	system("cls");
	printf("                    ************************************************\n                                      WELCOME\n                    ************************************************\n\n");
	printf("               YOU ARE--->\n\n               1. Vegetarian\n\n               2. Non Vegetarian\n\n                      OR\n\n               3. Back To Main Menu\n\n   Enter Your Choice  -->");
	int k;
	scanf("%d",&k);

	
	if(k==1)
	{
		system("cls");
		vegetarian();
	}
	else if(k==2)
	{
		system("cls");
		nonvegetarian();
	}
	else if(k==3)
	{
		system("cls");
		mainmenu();
	}
	else
	{
		
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		if(getch())
		customer();
	}
}
void vegetarian(void)
{
	int choice;
	int again;
	int quantity;
	
	double price=0;
	
	printf("        ****************************************\n                                  VEGETARIAN MENU\n                    ****************************************\n\n");
    printf("      1. Selroti ra achar               70/-\n  ");                  
	printf("      2. Thukpa                         60/-\n ");
	printf("      3. Naan ra Butter paneer          140/-\n  ");
	printf("      4. Mashala chiya  (Milk)          25/-\n  ");
	printf("      5. Thakali khana set              150/-\n  ");
	printf("       \t \t-->Dal\n         -->Paneer\n         -->Roti\n         -->Rice\n         -->Papad\n ");
	printf("      6. Back To Main Menu\n\n Enter Your Choice-->   ");
		
    printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 70*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 60*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d",&quantity);
		total=total + 140*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 25*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
	
			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d",&quantity);
		total=total + 150*(quantity);
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is : Rs. %.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
		
			details();
		}
			
	}
	else if(choice==6)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		vegetarian();
	}
}
void nonvegetarian(void)
{
	int choice;
	int again;
	int quantity;
	double price=0;
	printf("                                    **********************************************\n");
	printf("                                                  Non Veg. Menu\n");
	printf("                                    **********************************************\n");
     printf("1. Chicken Mo:Mo            100-\n\n");
	 printf("2. Mutton Chilly            300-\n\n");
	 printf("3. Chicken Biryani          85-\n\n");
	 printf("4. Sausage                  45-\n\n");
	 printf("5. Back To Main Menu\n\n\nEnter Your Choice");
	
	
	printf("\n\nEnter What You Want :");
	printf("\n\n");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("Quantity : ");
		scanf(" %d",&quantity);
		total=total + 100*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 300*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 85*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf(" %d",&quantity);
		total=total + 45*(quantity);
		printf("\n");
		printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonvegetarian();
		}
		else if(again==2)
		{
			printf("Your Total Amount Is :%.2lf\n\n",total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n",totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		nonvegetarian();
	}
}
void details(void)
{
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	printf("Please Give Your Contact Details \n");
	printf(" First Name : ");
	scanf("%s",name1);
	printf("Last Name : ");
	scanf("%s",name2);
	printf("Phone : ");
	scanf("%lld",&phone);
	printf("Address : ");
	scanf("%s",address);
	printf("\n\n");
	printf("Your Entered Details Are --->\n");
	
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n",name1,name2,phone);
	fclose(cust);
	printf("    -->First Name :  %s\n    -->Last Name   :  %s\n    -->Phone     :%lld \n    -->Address  :%s \n   ",name1,name2,phone,address);
	printf("\n\n\n");
	printf("                       ---------------------------------------------------------------------------------------------\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                       .....HAPPY ORDERING.....\n");
	printf("                       ---------------------------------------------------------------------------------------------\n");
	time_t current_time;   // not a primitive datatype
    time(&current_time);

    printf("\n                                     ===>  Current Date and Time: %s \n ", ctime(&current_time));
	printf("Press Any To The MainMenu.");
	if(getch())
	customer();
}

void aboutus(void)
{
	system("cls");
	printf("PEOPLE BEHIND THIS PROJECT :\n\n  -->Jayanti Thakur\t\t\tPAS077BEI020\n\n  -->Mandakini Sapkota\t\t\tPAS077BEI023\n\n  -->Monika Karki\t\t\tPAS077BEI024\n\n  -->Seemron Neupane\t\t\tPAS077BEI040\n\n  \a                   *****************************THANK YOU*****************************");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");
	if(getch())
	mainmenu();
}


