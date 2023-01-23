rwlock:rwlock.c linked_list.c operation.c
	gcc -g -o rwlock rwlock.c linked_list.c operation.c -lpthread -lm -O3
mutex:mutex.c linked_list.c operation.c
	gcc -g -o mutex mutex.c linked_list.c operation.c -lpthread -lm -O3
serial:serial_program.c linked_list.c operation.c
	gcc -o serial serial_program.c linked_list.c operation.c -lm -O3

