
obj = $(patsubst %.c,%.o,$(wildcard *.c))
calc.exe : $(obj)
	gcc -o $@ $^
clean : 
	rm *.o *.exe


