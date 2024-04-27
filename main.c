#include "header.h"

void main(){
	STD *headptr=0;
	int c=0,roll,rn;
	char op;
while(1){
	printf("***************STUDENT RECORD MENU****************\n");
	printf("a/A :Add new record\nd/D :delete a record\ns/S :show the list\nm/M :modify a record\nv/V :save\ne/E :exit\nt/T :sort the list\nl/L :delete all the records\nr/R :reverse the list\n");
	printf("Enter your choice:\n");
	scanf(" %c",&op);
	switch(op){
		case 'a':
		case 'A':sort_roll(&headptr);
			c=stud_count(headptr);
			roll=stud_roll(headptr,c);
			stud_add(&headptr,roll);break;
		case 'd':
		case 'D':rn=stud_del(headptr);
			if(rn==0){
			 break;
			 }else{
				delete_rn(&headptr,rn);
			 }break;
		case 's':
		case 'S':stud_show(headptr);break;
		case 'm':
		case 'M':stud_mod(&headptr);break;
		case 'v':
		case 'V':stud_save(headptr);break;
		case 'e':
		case 'E':exit(0);
		case 't':
		case 'T':sort(&headptr);break;
		case 'l':
		case 'L':delete_all(&headptr);break;
		case 'r':
		case 'R':reverse_links(&headptr);break;
		default:printf("Entered option is not correct\n");
	}
}
}
