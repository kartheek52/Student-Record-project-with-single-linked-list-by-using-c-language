#include "header.h"

int stud_count(STD *ptr){
	int c=0;
	while(ptr){
		c++;
		ptr=ptr->next;
	}
	return c;
}

int stud_roll(STD *ptr,int c){
	int i=0,r=1;
	if(c<=1)
		return ++c;
	STD *t=ptr;
	int *a=malloc(sizeof(int)*c);
	for(;t;t=t->next,i++){
		a[i]=t->rollno;
	}
	for(i=0;a[i]==r;i++){
		r++;
		if(i==c)
		break;
	}
		return r;
}

void stud_add(STD **ptr,int n){
	STD *new;
	new=malloc(sizeof(STD));
	new->rollno=n;
	printf("Enter %d student name and details\n",new->rollno);
	scanf("%s %f",new->name,&new->marks);
		if(*ptr==0||n==1){
		new->next=*ptr;
		*ptr=new;
		}else{
			STD *nex;
			nex=*ptr;
			while((nex->rollno)<(new->rollno)){
				if(nex->next==0 || (nex->next->rollno)>(new->rollno)){
					break;
				}
				nex=nex->next;
			}
			new->next=nex->next;
			nex->next=new;
		}
}
