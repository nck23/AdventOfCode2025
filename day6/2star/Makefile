SRCS = src/main.c src/calc_diag.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -O0 -Iinclude -ggdb3


main: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o main
src/%.o: src/%.c
	gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f src/*.o main