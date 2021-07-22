INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/stack/stack.c ./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./tests/stack_funcs/st_rotate/test.c"

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
testfunc "./a.out 2 1 3" "ra\n1\n3\n2\nlast:2\nlen:3\n"
testfunc "./a.out 5 2 3 1" "ra\n2\n3\n1\n5\nlast:5\nlen:4\n"

rm a.out
exit $RTN
