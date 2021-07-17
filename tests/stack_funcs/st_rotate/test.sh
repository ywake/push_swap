INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/data/stack.c ./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./tests/stack_funcs/st_rotate/test.c"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -g $INCLUDES $SRCS $LIBS

RTN=0
function testfunc() {
	echo "$1"
	diff <($1) <(echo -en $2)
	RTN=$(($RTN | $?))
}

testfunc "./a.out 1 2 3" "ra\n2\n3\n1\nlen:3\n"
testfunc "./a.out 1 2 3 5" "ra\n2\n3\n5\n1\nlen:4\n"
testfunc "./a.out 1" "1\nlen:1\n"

rm a.out
exit $RTN
