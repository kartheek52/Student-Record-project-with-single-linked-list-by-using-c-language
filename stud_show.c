#include "header.h"

void stud_show(STD *ptr){
	if(ptr==0){
		printf("Records not found\n");
		return;
	}
	printf("\nStudents data:\n");
	while(ptr){
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}