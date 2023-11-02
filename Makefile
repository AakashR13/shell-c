shell: *.c
	gcc -g -o shell *.c

clean:
	rm -f shell

cleanHistory:
	rm -f history.txt