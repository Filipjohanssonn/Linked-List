prog: 			main.o driv.o list.o
			gcc -o program main.o driv.o
			

main.o:			main.c driv.c list.c
			gcc -c main.c

driv.o:			driv.c driv.h
			gcc -c driv.c
			
list.o:			list.c list.h
			gcc -c list.c

clean: 
	rm *.o
