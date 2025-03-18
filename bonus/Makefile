NAME_C = client_bonus
NAME_S = server_bonus
SRC_C = client_bonus.c  utils_bonus.c
SRC_S = server_bonus.c  utils_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS_S = $(SRC_S:.c=.o)
OBJS_C = $(SRC_C:.c=.o)

all : $(NAME_S) $(NAME_C)

$(NAME_C) : $(OBJS_C)
	$(CC) $(CFLAGS) $(SRC_C) -o $(NAME_C)

$(NAME_S) : $(OBJS_S)
	$(CC) $(CFLAGS) $(SRC_S) -o $(NAME_S)

clean :
	rm -rf $(OBJS_S) $(OBJS_C) 

fclean : clean
	rm -rf $(NAME_S) $(NAME_C)

.SECONDARY: $(OBJS)
re : fclean all