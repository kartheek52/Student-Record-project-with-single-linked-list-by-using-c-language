compiler = cc
target = main.o other.o stud_add.o stud_del.o stud_mod.o stud_save.o stud_show.o
exe:$(target)
	$(compiler) $(target) -o exe

main.o : main.c
	$(compiler) -c main.c
other.o : other.c
	$(compiler) -c other.c
stud_add.o : stud_add.c
	$(compiler) -c stud_add.c
stud_del.o : stud_del.c
	$(compiler) -c stud_del.c
stud_mod.o : stud_mod.c
	$(compiler) -c stud_mod.c
stud_save.o : stud_save.c
	$(compiler) -c stud_save.c
stud_show.o : stud_show.c
	$(compiler) -c stud_show.c


clear :
	@echo "cleaning up.........."
	@rm -v *.o
