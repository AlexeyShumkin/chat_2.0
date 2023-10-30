TARGET = release
CC = g++

$(TARGET) : main.o chat.o database.o
	$(CC) main.o chat.o database.o -o $(TARGET)

main.o : main.cpp
	$(CC) -c main.cpp -o main.o

chat.o : chat.cpp
	$(CC) -c chat.cpp -o chat.o

database.o : database.cpp
	$(CC) -c database.cpp -o database.o

clean :
	rm *.o

uninstall:
	rm $(TARGET)