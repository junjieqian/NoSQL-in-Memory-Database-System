CC = g++
DEBUG = -g
OBJS = database.o cmdline.o
CFLAGS = -c -Wall $(DEBUG) -I../include
LDFLAGS = -pthread

Simple_DataBase:$(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o Simple_DataBase

database.o:database.cc
		$(CC) $(CFLAGS) database.cc

cmdline.o:cmdline.cc
		$(CC) $(CFLAGS) cmdline.cc

.PHONY:clean

clean:
		rm -f *.o Simple_DataBase