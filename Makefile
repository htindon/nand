NAME	= parser
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -O3 -I.
INCL	= libasm.h
OBJ		= parser.c \
		  get_line.c \
		  init_list.c \
		  push_last.c \
		  trim.c \
		  print_list.c \
		  parse_symbols.c \
		  find_char.c \
		  file_to_list.c \
		  apply_to_list.c \
		  strip_char.c

%.o: %.c $(INCL)
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(NAME)

re: clean
	make

.PHONY: re clean
