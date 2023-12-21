NAME = pushswap.a
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
PRINTFDIR = ./printf
LIBFTDIR = ./../libft

SRCS = lst_create.c main.c swap_command.c lst_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) .
	@mv $(PRINTFNAME) $(NAME)

$(NAME): makeprintf $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@cd $(PRINTFDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(PRINTFDIR) && make fclean

compil: 
	$(CC) $(CFLAGS) -o pushswap_test lst_create.c $(PRINTFDIR)/*.c $(LIBFTDIR)/*.c -I$(LIBFTDIR)

re: fclean all compil

.PHONY: all clean fclean re compil
