NAME = pushswap.a
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
PRINTFDIR = ./printf

SRCS =  lst_create.c

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
	cc lst_create.c ./ft_printf/*.c ./../libft/*.c

re: fclean all compil

.PHONY:                         all bonus clean fclean re compil
