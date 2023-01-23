test:all.c linked_list.c operation.c mutex.c rwlock.c
	gcc -g -o all all.c linked_list.c operation.c mutex.c rwlock.c -lpthread -lm -O3
all:rwlock.c linked_list.c operation.c mutex.c serial_program.c
	gcc -g -o rwlock rwlock.c linked_list.c operation.c -lpthread -lm -O3
	gcc -g -o mutex mutex.c linked_list.c operation.c -lpthread -lm -O3
	gcc -o serial serial_program.c linked_list.c operation.c -lm -O3
rwlock:rwlock.c linked_list.c operation.c
	gcc -g -o rwlock rwlock.c linked_list.c operation.c -lpthread -lm -O3
mutex:mutex.c linked_list.c operation.c
	gcc -g -o mutex mutex.c linked_list.c operation.c -lpthread -lm -O3
serial:serial_program.c linked_list.c operation.c
	gcc -o serial serial_program.c linked_list.c operation.c -lm -O3

