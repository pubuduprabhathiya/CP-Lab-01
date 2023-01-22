mutex:mutex.c linked_list.c operation.c
	gcc -o mutex mutex.c linked_list.c operation.c -lm -O3
serial:serial_program.c linked_list.c operation.c
	gcc -o serial serial_program.c linked_list.c operation.c -lm -O3

