CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = main.c s21_cat.c process_line_b.c process_line_e.c process_line_n.c \
      process_line_s.c process_line_t.c process_line_v.c

OBJ = *.o

all: s21_cat

s21_cat: $(OBJ)
	$(CC) $(OBJ) -o s21_cat

$(OBJ):
	$(CC) $(CFLAGS) -c $(SRC)

test: all
	chmod 777 tests.sh
	./tests.sh

clean:
	rm -f $(OBJ) s21_cat

