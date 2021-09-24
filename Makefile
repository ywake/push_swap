NAME	:= push_swap
B_NAME	:= checker
CC		:= gcc
INCLUDE	:= -I./includes -I./Libft
CFLAGS	:= -g -Wall -Werror -Wextra $(INCLUDE)
LIBFT	:= ./libft.a
LIBS	:= -L. -lft
SRCDIR	:= ./srcs/
SRCS	:= main.c error.c debug.c \
			data/data.c data/validation.c\
			stack/stack.c stack/stack2.c stack/command.c\
			algo/quick_sort.c algo/small_swap.c algo/dfs.c\
			opt/optimize.c opt/rm_nonsense.c
OBJS	:= $(SRCS:%.c=$(SRCDIR)%.o)
B_SRCS	:= checker/main.c error.c debug.c \
			data/data.c data/get_next_line.c data/validation.c \
			stack/stack.c stack/stack2.c stack/command.c
B_OBJS	:= $(B_SRCS:%.c=$(SRCDIR)%.o)

.PHONY: all clean fclean re norm bonus bonus_leak test

all: $(NAME)

%.o: $(SRCDIR)%.c *.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): ./Libft/*.c
	$(MAKE) bonus -C ./Libft
	cp ./Libft/libft.a ./libft.a

$(NAME):  $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

bonus: $(B_NAME)

$(B_NAME): $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $(B_NAME) $(LIBS)

clean:
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	$(MAKE) fclean -C ./Libft
	rm -f libft.a
	rm -f out out_checker err leaksout
	rm -f $(NAME) $(B_NAME)
	rm -rf $(NAME).dSYM $(B_NAME).dSYM a.out.dSYM

re: fclean all

norm:
	@printf "\e[31m"; norminette | grep -v -e ": OK!" -v -e "Missing or invalid header. Header are being reintroduced as a mandatory part of your files. This is not yet an error." \
    && exit 1 \
	|| printf "\e[32m%s\n\e[m" "Norm OK!"; printf "\e[m"

leak: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) ./tests/sharedlib.c -o $(NAME) $(LIBS)

bonus_leak: $(LIBFT) $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) ./tests/sharedlib_checker.c -o $(B_NAME) $(LIBS)

autotest: $(LIBFT)
	bash auto_test.sh $(TEST)\
	&& $(MAKE) norm
