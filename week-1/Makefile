% : %.c
	gcc $< -I ~/apue/apue.3e/include \
	-L ~/apue/apue.3e/lib -lapue -lpthread \
	-o $@ -g


% : %.cpp
	g++ $< -o $@ -g -lpthread

.PHONY : gdb

gdb : 
	gdb --args ./demo 06.txt

