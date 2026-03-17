obj=$(patsubst %.c,%.o,$(wildcard *.c))
adbook.exe: $(obj)
	gcc -o $@ $^
clean:
	rm *.exe *.o	 