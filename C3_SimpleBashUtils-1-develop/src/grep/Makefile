CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c s21_grep.c parsingfunction.c

OBJ = *.o

all: s21_grep

s21_grep: $(OBJ)
	$(CC) $(OBJ) -o s21_grep

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

test: all
	chmod 777 tests.sh
	./tests.sh

clean:
	rm -f $(OBJ) s21_grep
