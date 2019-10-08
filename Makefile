PROJECT_NAME=TiresCalibrate
CC=C:\\MinGW\\bin\\g++.exe
WINDRES=C:\\MinGW\\bin\\windres.exe
CFLAGS=-m32 -static -lgcc -s -g3


all: main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

my.o: my.rc
	$(WINDRES) my.rc my.o

my.rc: icon.ico
	
main: main.o my.o
	$(CC) $(CFLAGS) -o $(PROJECT_NAME) main.o my.o

clean:
	rm -rf *.exe *.o *.res
	
	