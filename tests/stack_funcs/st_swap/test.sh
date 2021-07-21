INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/data/stack.c ./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./tests/stack_funcs/st_swap/test.c"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -g $INCLUDES $SRCS $LIBS
if [ $? -ne 0 ]; then
	exit 1
fi

RTN=0
function testfunc() {
	echo "$1"
	diff <($1) <(echo -en $2)
	RTN=$(($RTN | $?))
}

testfunc "./a.out 1" "1\nlast:1\nlen:1\n"
testfunc "./a.out 1 2" "sa\n2\n1\nlast:1\nlen:2\n"
testfunc "./a.out 1 2 3" "sa\n2\n1\n3\nlast:3\nlen:3\n"

rm a.out
exit $RTN
