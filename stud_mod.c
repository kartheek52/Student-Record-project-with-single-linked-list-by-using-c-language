#include "header.h"

void stud_mod(STD **ptr){
char ch;
int flag=1;	
STD *t=*ptr;
while(flag){
printf("R/r: to search a rollno\nN/n:to search a name\nP/p:percentage based\n");
printf("Enter which record to search for modification\n");
scanf(" %c",&ch);
		switch(ch){
			case 'R':
			case 'r':mod_rn(ptr);flag=0;break;
			case 'N':
			case 'n':mod_name(ptr);flag=0;break;
			case 'P':
			case 'p':mod_percent(ptr);flag=0;break;
			default:printf("Choose correct option\n");
			}
}
}

void mod_percent(STD **ptr){
STD *t=*ptr;
float f;
printf("Enter percentage to search\n");
scanf("%f",&f);
int n=mark_cmp(f,t);
	if(n==0){
		printf("Entered percentage not found\n");
		return;
	}
	if(n==1){
		while(t){
			if(f==t->marks)
				break;
			t=t->next;
		}	
		printf("%d %s %f\n",t->rollno,t->name,t->marks);
		printf("Enter name and marks for modification\n");
		scanf("%s %f",t->name,&(t->marks));
	}else{		
		while(t){
			if(f==t->marks){
				printf("%s %d\n",t->name,t->rollno);
			}
			t=t->next;
		}
		mod_rn(ptr);
}
}


void mod_name(STD **ptr){
STD *temp=*ptr;
char n[20];
printf("Enter name to search\n");
scanf("%s",n);
int num=name_cmp(n,temp);
	if(num==0){
		printf("name not found\n");
		return;
	}
	if(num==1){
		while(temp){
			if(strcmp(n,temp->name)==0)
				break;

			temp=temp->next;
		}
		printf("%d %s %f\n",temp->rollno,temp->name,temp->marks);
		printf("Enter name and marks for modification\n");
		scanf("%s %f",temp->name,&(temp->marks));
	}else{
		while(temp){
			if(strcmp(n,temp->name)==0){
				printf("%s %d\n",temp->name,temp->rollno);
			}
			temp=temp->next;
		}
		mod_rn(ptr);
}
}

void mod_rn(STD **ptr){
	int rn;
	STD *temp=*ptr;
	char name[20];
	float marks;
	if(temp==0){
		printf("no records found\n");
		return;
	}
	printf("Enter roll number to modify\n");
	scanf("%d",&rn);
	while(temp->rollno!=rn && temp->next!=0)
		temp=temp->next;
	if(temp->rollno==rn){
	printf("Student details %d %s %f\n",temp->rollno,temp->name,temp->marks);
	printf("Enter student name and marks to change\n");
	scanf("%s %f",temp->name,&(temp->marks));
	}else{
		printf("Roll number not found\n");
	}
}

int name_cmp(char *n,STD *ptr){
int c=0;
while(ptr){
	if(strcmp(n,ptr->name)==0)
		c++;
	ptr=ptr->next;
}
return c;
}

int mark_cmp(float f,STD *ptr){
int c=0;
while(ptr){
	if(f==ptr->marks)
		c++;
	ptr=ptr->next;
}
return c;
}