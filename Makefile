NAME	:= push_swap
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libs/libft.a
LIBS	:= -L. -lft
SRCDIR	:= ./srcs/
SRCS	:= main.c error.c debug.c \
			data/data.c data/validation.c data/stack.c data/stack2.c\
			algo/quick_sort.c algo/small_swap.c \
			opt/optimize.c opt/rm_nonsense.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)
BONUSFLG:= .bonus_flg

.PHONY: all clean fclean re bonus test

all: $(NAME)

%.o: $(SRCDIR)%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft
	mv ./Libft/libft.a ./libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(BONUSFLG)

$(BONUSFLG): $(B_OBJS) $(LIBFT)
	@touch $(BONUSFLG)
	$(CC) $(B_OBJS) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS)

fclean: clean
	rm -f libs/libft.a
	rm -f $(NAME)

re: fclean all

norm:
	@printf "\e[31m"; norminette srcs includes Libft tests/*/test.c tests/*/*/test.c | grep -v ": OK!" \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"; printf "\e[m"

test: $(OBJS) $(LIBFT)
	$(CC) $(LIBS) $(OBJS) ./tests/sharedlib.c -o $(NAME)

autotest:
	bash auto_test.sh $(TEST)\
	&& $(MAKE) norm
