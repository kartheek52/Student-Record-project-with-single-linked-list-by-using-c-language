#include "header.h"

void stud_save(STD *ptr){
char opt;
printf("Enter\nS/s: save and exit\nE/e: exit without saving\n");
scanf(" %c",&opt);
switch(opt){
	case 'S':
	case 's':file_cpy(ptr);
		 exit(0);
	case 'E':
	case 'e':exit(0);
	default :printf("Wrong option choosen\n");
}
}

void file_cpy(STD *ptr){
	FILE *fp=fopen("student","w");
	if(fp==0){
		printf("file not found\n");
		return;
	}
	fprintf(fp,"Roll_Number\tName\tMarks\n");
	while(ptr){
		fprintf(fp,"%d\t%s\t%f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	printf("Stdents data saved successfully\n");
	fclose(fp);
}