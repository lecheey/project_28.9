CC = g++
SRC = main.cpp
TARGET = mergeSort

lightchatcli: $(SRC) lib
	$(CC) -o $(TARGET) $(SRC) -L. -lMyLib

lib: merge_sort.o
	ar rc libMyLib.a merge_sort.o

liblogger: merge_sort.cpp merge_sort.h
	$(CC) -o megre_sort.o merge_sort.cpp -c

clear:
	rm *.o *.a
