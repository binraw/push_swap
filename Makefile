NAME = push_swap
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
PRINTFDIR = ./printf
LIBFTDIR = ./printf/libft

SRCS = lst_create.c main.c swap_command.c lst_utils.c threenum.c fivenum.c finder.c big_lst_algo.c check.c count_rotate.c rotation.c check_error.c rotation_utils.c transfer_utils.c big_utils.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) $(NAME)

$(NAME): makeprintf $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(PRINTFDIR) -lftprintf

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTFDIR) && make fclean

compil: 
	$(CC) $(CFLAGS) -o pushswap_test $(SRCS) $(PRINTFDIR)/*.c $(LIBFTDIR)/*.c -I$(LIBFTDIR) -I$(PRINTFDIR)

re: fclean all compil

.PHONY: all clean fclean re compil

