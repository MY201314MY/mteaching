#### Makefile

```makefile
main: main.o rtthread.o 
	$(CC) $^ -o $(@)

main.o: main.c
	$(CC) -c $^ -o $(@)

rtthread.o: rtthread.c
	$(CC) -c $^ -o $(@)

semaphore:
	$(CC) $@.c -o $(@) -lpthread

clean:main
	rm -f $^
```

