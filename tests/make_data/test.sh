INCLUDES="-I./includes -I./Libft"
SRCS="./srcs/data.c ./srcs/validation.c ./srcs/error.c ./tests/make_data/test.c"
LIBS="-L. -lft"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -o push_swap -g $INCLUDES $SRCS ./tests/sharedlib.c $LIBS

RTN=0
function testfunc() {
	echo "$1"
	diff <(./push_swap $1) <(echo -en $2)
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		./push_swap $1 > /dev/stderr
		RTN=1
	fi
}

testfunc "1"				"1\n"
testfunc "1 2 3"			"1\n2\n3\n"
testfunc "1 2147483647 3"	"1\n2147483647\n3\n"
testfunc "1 -2147483648 3"	"1\n-2147483648\n3\n"
testfunc "-1 -3 -2"			"-1\n-3\n-2\n"

rm push_swap leaksout
exit $RTN
