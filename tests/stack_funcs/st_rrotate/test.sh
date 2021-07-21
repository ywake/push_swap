INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/data/stack.c ./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./tests/stack_funcs/st_rrotate/test.c"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -g $INCLUDES $SRCS $LIBS
if [ $? -ne 0 ]; then
	exit 1
fi

RTN=0
function testfunc() {
	echo "$1"
	# $1>/dev/stderr
	diff <($1) <(echo -en $2)
	RTN=$(($RTN | $?))
}

testfunc "./a.out 1" "1\nlast:1\nlen:1\n"
testfunc "./a.out 1 2" "rra\n2\n1\nlast:1\nlen:2\n"
testfunc "./a.out 1 2 3" "rra\n3\n1\n2\nlast:2\nlen:3\n"
testfunc "./a.out 1 2 3 5" "rra\n5\n1\n2\n3\nlast:3\nlen:4\n"

rm a.out
exit $RTN
