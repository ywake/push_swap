INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/stack.c ./srcs/input.c ./srcs/error.c ./tests/stack_funcs/st_push/test.c"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -g $INCLUDES $SRCS $LIBS

RTN=0
function testfunc() {
	echo "$1"
	diff <($1) <(echo -en $2)
	RTN=$(($RTN | $?))
}

testfunc "./a.out 1 2 3" "pb\n2\n3\nlen:2\n-\n1\nlen:1\n"
testfunc "./a.out 1" "pb\nlen:0\n-\n1\nlen:1\n"

rm a.out
exit $RTN
