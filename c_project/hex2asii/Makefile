src = $(shell ls *.c)
obj = $(src:.c=.o)
bin = a

$(bin):$(obj)
	gcc $^ -o $@

%.o:%.c
	gcc -g -c -std=c99 $< -o $@

clean:
	rm -f $(bin);
	rm -f $(obj);

