//PATIENT RECORD SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


typedef struct node
{
    int num;//Patient's Id
    char name[30];//Patient's Name
    int age;//Patient's Age
    char disease[50];//Patient's Disease
    int bedno;//Patient's Bed No.
    struct node* next;
}node;

typedef struct
{
    node* start;
}LL;

void insertEnd(LL *l,int pnum,char pname[30],int page,char pdisease[50],int pbedno)
{
    node *newrec,*p;
	newrec=(node*)malloc(sizeof(node));//Dynamically allocating memory

	newrec->num=pnum;
	strcpy(newrec->name,pname);
	newrec->age=page;
	strcpy(newrec->disease,pdisease);
	newrec->bedno=pbedno;

	newrec->next=NULL;//make the node as last

	if(l->start==NULL)//is this the first node?
        l->start=newrec;

	else
	{
		p=l->start;
		while(p->next!=NULL)//traverse the LL until you reach the last node
        {
             p=p->next;//go to next node
        }
		p->next=newrec;//link last node with current node
	}
}

void display(LL *l)
{
	node *p;
	int i=0;
	if(l->start==NULL)//if no records are present
	{
		printf("\tRECORD IS EMPTY\n");
		return;
	}
	p=l->start;

    printf("\t\t\t\t\t\tLIST OF PATIENTS\n\n");
    printf("\tSR.NO.\t\tID\t\tNAME\t\tAGE\t\tDISEASE\t\tBED NO.\n");

	while(p!=NULL)//Traversing through the list
	{
        i++;
        printf("\t%d\t\t%d\t\t%s\t\t%d\t\t%s\t\t%d\n",i,p->num,p->name,p->age,p->disease,p->bedno);//printing the records in the table form
		p=p->next;//go to next node
	}
	printf("\n");
}


void search(LL *l,char pname[30])
{
	node *p;
	p=l->start;

	while(p!=NULL)//Traversing the LL
	{
		if(strcmp(pname,p->name)==0)//If entry found, print it
        {
            printf("\n");
            printf("\t||PATIENT ID : %d ||",p->num);
            printf("\t||PATIENT NAME : %s ||",p->name);
            printf("\t||AGE: %d ||",p->age);
            printf("\t||DISEASE: %s ||",p->disease);
            printf("\t||BED NO.: %d ||",p->bedno);
            break;
		}
		else
		{
		    p=p->next;//go to next node
		}
	}
	if(p==NULL)//if record not found
        printf("\t%s RECORD NOT FOUND\n",pname);

}

int count(LL *l)
{
	node *p;
	int c=0;
	p=l->start;

	while(p!=NULL)
	{
		c++;//increment counter if node exist
		p=p->next;//go to next node
	}
	return c;
}

void deleteElement(LL *l,char pname[30])
{
    node *p,*q;//p is node to be deleted
	if(l->start==NULL)//if no entry in the list
	{
		printf("\tRECORD LIST IS EMPTY\n");
		return ;
	}
	if(strcmp(l->start->name,pname)==0)//if node to be deleted is first node
	{
		p=l->start;
		l->start=l->start->next;//or write q->next
            //update start, start will now point to second node
		p->next=NULL;
		return;
	}

	q=l->start;
	while(q->next!=NULL)
	{
		if(strcmp(pname,q->next->name)==0)//entry matches found, break while
            break;
		else
            q=q->next;//go to next node
	}
	p=q->next;//current node becomes previous node
	if(p==NULL)//if desired node not found
	{
		printf("\tTHE RECORD FOR %s IS NOT FOUND\n",pname);
	}
	else
	{
	    q->next=p->next;//deleting the node
        p->next=NULL;
	}
}

int main()
{
	LL l1;
	int ch,pnum,page,pbedno;
	char pname[30],pdisease[50],d,c;
    l1.start=NULL;
    printf("*******************************************************************************************************\n*******************************************||CITY HOSPITAL||*******************************************\n*******************************************************************************************************\n");
	printf("\n\t MENU:\n");
    printf("\n\t1. INSERT RECORD\n");
    printf("\t2. DELETE RECORD\n");
    printf("\t3. SEARCH RECORD\n");
    printf("\t4. TOTAL PATIENTS\n");
    printf("\t5. DISPLAY RECORDS\n");
    printf("\t6. EXIT\n");

	while(1)
	{
        printf("\n\tPLEASE ENTER AN OPTION : ");
        scanf("%d",&ch);
        printf("\n-------------------------------------------------------------------------------------------------------\n");
		switch(ch)
		{
            case 1:

                    printf("\tENTER PATIENT'S ID : ");
                    scanf("%d",&pnum);
                    scanf("%c",&d);
                    printf("\n\tENTER PATIENT'S NAME : ");
                    gets(pname);
                    printf("\n\tENTER PATIENT'S AGE : ");
                    scanf("%d",&page);
                    printf("\n\tENTER PATIENT'S DISEASE : ");
                    scanf("%s",&pdisease);
                    //gets(pdisease);
                    printf("\n\tASSIGN BED NO : ");
                    scanf("%d",&pbedno);

                    insertEnd(&l1,pnum,pname,page,pdisease,pbedno);

                    printf("\n\tLIST UPDATED \n ");
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    break;

            case 2:
                    printf("\tENTER NAME TO DELETE : ");
                    scanf("%c");
                    gets(pname);
                    deleteElement(&l1,pname);
                    printf("\n\t LIST UPDATED \n ");
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    break;

            case 3: printf("\tENTER NAME TO SEARCH : ");
                    scanf("%c");
                    gets(pname);
                    search(&l1,pname);
                    printf("\n-------------------------------------------------------------------------------------------------------\n");
                    break;

            case 4:
                    printf("\tTOTAL NUMBER OF PATIENTS : %d\n",count(&l1));
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    break;

            case 5:
                    display(&l1);
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    break;

            case 6:
                    exit(0);
            default:
                    printf("\tINVALID CHOICE !!!\n");
                    printf("-------------------------------------------------------------------------------------------------------\n");
            }
	}

	return 0;
}

/*****************************************************************************************************************************************
