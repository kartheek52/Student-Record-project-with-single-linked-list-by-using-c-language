#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct student{
	int rollno;
	char name[20];
	float marks;
	struct student *next;
}STD;

int stud_count(STD *);
void stud_add(STD **,int);
int stud_del(STD *);
void stud_show(STD *);
void stud_mod(STD **);
void stud_save(STD *);
void stud_sort(STD **);
void del_all(STD **);
void stud_revli(STD **);
int stud_roll(STD *,int);
char del_op();
int name_cmp(char *,STD *);
void delete_rn(STD **,int);
void mod_rn(STD **);
void mod_name(STD **);
void mod_percent(STD **);
int mark_cmp(float,STD *);
void file_cpy(STD *);
void sort(STD **);
void sort_name(STD **);
void sort_roll(STD **);
void sort_perc(STD **);
void delete_all(STD **);
void reverse_links(STD **);

