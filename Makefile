CC = g++
DEBUG = -g
OBJS = database.o cmdline.o
CFLAGS = -c -Wall $(DEBUG) -I./include
LDFLAGS = -pthread

Simple_DataBase:$(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o Simple_DataBase

database.o:database.cc
		$(CC) $(CFLAGS) src/database.cc

cmdline.o:cmdline.cc
		$(CC) $(CFLAGS) src/cmdline.cc

.PHONY:clean

clean:
		rm -f *.o Simple_DataBase