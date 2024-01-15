NAME = pushswap
PRINTFNAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
PRINTFDIR = ./printf
LIBFTDIR = ./printf/libft

SRCS = lst_create.c main.c swap_command.c lst_utils.c threenum.c fivenum.c finder.c big_lst_algo.c check.c count_rotate.c

# Remplacez .c par .o pour obtenir les noms des fichiers objets
OBJS = $(SRCS:.c=.o)

all: $(NAME)

makeprintf:
	@make -C $(PRINTFDIR)
	@cp $(PRINTFDIR)/$(PRINTFNAME) $(NAME)

# Ajoutez les dépendances pour les fichiers objets
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

