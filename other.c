#include "header.h"

void sort(STD **ptr){
if(*ptr==0){
	printf("Rocords not found\n");
	return;
}
	char opt;
int flag=1;
	while(flag){
		printf("Enter\nN/n: Sort with name\nP/p: Sort withpercentage\n");
		scanf(" %c",&opt);
		switch(opt){
			case 'n':
			case 'N':sort_name(ptr);flag=0;break;
			case 'p':
			case 'P':sort_perc(ptr);flag=0;break;
			default :printf("Worng option choosen\n");
		}
	}	
}

void sort_name(STD **ptr){
STD *p=*ptr;
STD *q,t;
int i,j,c=stud_count(*ptr);
	for(i=0;i<c-1;i++){
		q=p->next;
		for(j=0;j<c-i-1;j++){
			if(strcmp(p->name,q->name)>0){
				t.rollno=p->rollno;
				strcpy(t.name,p->name);
				t.marks=p->marks;

				p->rollno=q->rollno;
				strcpy(p->name,q->name);
				p->marks=q->marks;

				q->rollno=t.rollno;
				strcpy(q->name,t.name);
				q->marks=t.marks;

			}
			q=q->next;
		}
		p=p->next;
	}
	printf("After sorting\n");
	stud_show(*ptr);
}





void sort_roll(STD **ptr){
STD *p=*ptr;
STD *q,t;
int i,j,c=stud_count(*ptr);
	for(i=0;i<c-1;i++){
		q=p->next;
		for(j=0;j<c-i-1;j++){
			if(p->rollno > q->rollno){
				t.rollno=p->rollno;
				strcpy(t.name,p->name);
				t.marks=p->marks;

				p->rollno=q->rollno;
				strcpy(p->name,q->name);
				p->marks=q->marks;

				q->rollno=t.rollno;
				strcpy(q->name,t.name);
				q->marks=t.marks;

			}
			q=q->next;
		}
		p=p->next;
	}
}


void sort_perc(STD **ptr){
STD *p=*ptr;
STD *q,t;
int i,j,c=stud_count(*ptr);
	for(i=0;i<c-1;i++){
		q=p->next;
		for(j=0;j<c-i-1;j++){
			if(p->marks < q->marks){
				t.rollno=p->rollno;
				strcpy(t.name,p->name);
				t.marks=p->marks;

				p->rollno=q->rollno;
				strcpy(p->name,q->name);
				p->marks=q->marks;

				q->rollno=t.rollno;
				strcpy(q->name,t.name);
				q->marks=t.marks;

			}
			q=q->next;
		}
		p=p->next;
	}
	printf("After Sorting\n");
	stud_show(*ptr);
}

void reverse_links(STD **ptr){
	if(*ptr==0){
		printf("records not found\n");
		return;
	}
STD *t=*ptr;
int i=0,c=stud_count(*ptr);
	if(c>1){
		STD **arr=malloc(sizeof(STD *)*c);
		while(t){
			arr[i++]=t;
			t=t->next;
		}
		for(i=1;i<c;i++)
			arr[i]->next=arr[i-1];
		arr[0]->next=0;
		*ptr=arr[c-1];
	}
}

void delete_all(STD **ptr){
	if(*ptr==0){
		printf("no records found\n");
		return;
	}

	STD *del=*ptr;
	int c=1;
	while(del){
		*ptr=del->next;
		printf("deleted node %d\n",c++);
		free(del);
		del=*ptr;
	}
	printf("All records deleted successfully\n");
}

