INCLUDES="-I./includes -I./Libft"
SRCS="./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./srcs/debug.c\
		./srcs/stack/stack.c ./srcs/stack/stack2.c ./srcs/stack/command.c \
		./srcs/algo/small_swap.c ./srcs/algo/dfs.c ./tests/dfs/stackB/test.c"
LIBS="-L. -lft"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -o push_swap -g $INCLUDES $SRCS $LIBS
if [ $? -ne 0 ]; then
	exit 1
fi

array=(
	"1 2 3"
	"1 3 2"
	"2 1 3"
	"3 1 2"
	"2 3 1"
	"3 2 1"
	# "1 2 3 4"
	# "1 2 4 3"
	# "1 3 2 4"
	# "1 3 4 2"
	# "1 4 2 3"
	# "1 4 3 2"
	# "2 1 3 4"
	# "2 1 4 3"
	# "2 3 1 4"
	# "2 3 4 1"
	# "2 4 1 3"
	# "2 4 3 1"
	# "3 1 2 4"
	# "3 1 4 2"
	# "3 2 1 4"
	# "3 2 4 1"
	# "3 4 1 2"
	# "3 4 2 1"
	# "4 1 2 3"
	# "4 1 3 2"
	# "4 2 1 3"
	# "4 2 3 1"
	# "4 3 1 2"
	# "4 3 2 1"
	# "4 1 5 3 2"
	# "5 4 3 2 -2147483648"
	# "$(gen_randint 5 -3 3)"
	)

make bonus
if [ $? -ne 0 ]; then
	exit 1
fi

for i in ${!array[@]};
do
	echo --- "${array[$i]}" ---
	./push_swap ${array[$i]} > out
	# cat out
	# printf "\e[33m%s\n\e[m" $(cat out | wc -l)
	diff <(cat out | ./checker ${array[$i]}) <(echo "OK") >/dev/null
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
	rm out
done
exit $FLG
