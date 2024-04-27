#include "header.h"

int stud_del(STD *ptr){
	if(ptr==0){
		printf("Records not found\n");
		return 0;
	}
	int flag=0;
	char ch;
while(1){
	printf("R/r Enter roll no to delete\nN/n Enter name to delete\nEnter option\n");
	scanf(" %c",&ch);
switch(ch){
	case 'r':
	case 'R':
	int roll;
	printf("Enter roll number\n");
	scanf("%d",&roll);
	return roll;
	break;
	case 'n':
	case 'N':
		char s[20];
		STD *name=ptr;
		int r;
		printf("Enter name to delete\n");
		scanf("%s",s);
		int num=name_cmp(s,name);
		if(num==0){
			printf("Entered name data is not present\n");
			return 0;
		}else if(num==1){
			while(name){
				if(strcmp(s,name->name)==0){
					r=name->rollno;
					break;
				}
				name=name->next;
			}
			return r;
		}else{
			while(name){
				if(strcmp(s,name->name)==0){
					printf("%s %d\n",name->name,name->rollno);
				}
				name=name->next;
			}
			printf("enter one student roll number to delete\n");
			scanf("%d",&r);
			return r;
		}
	break;
	default:printf("enter correct option\n");
}
}
}

void delete_rn(STD **headptr,int n){
	STD *del=*headptr,*prev;
	while(del){
		if(del->rollno==n){
			if(del==*headptr)
				*headptr=del->next;
			else
				prev->next=del->next;
			free(del);
			printf("%d roll no data has been deleted successfully\n",n);
			return;
		}
	prev=del;
	del=del->next;
	}
	printf("roll number not found\n");
}