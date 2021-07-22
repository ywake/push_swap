INCLUDES="-I./includes -I./Libft"
LIBS="-L. -lft"
SRCS="./srcs/stack/stack.c ./srcs/data/data.c ./srcs/data/validation.c ./srcs/error.c ./tests/stack_funcs/st_push/test.c"

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

testfunc "./a.out 1" "pb\nlast:(null)\nlen:0\n-\n1\nlast:1\nlen:1\n"
testfunc "./a.out 1 2" "pb\npb\nlast:(null)\nlen:0\n-\n2\n1\nlast:1\nlen:2\n"
testfunc "./a.out 1 2 3" "pb\npb\n3\nlast:3\nlen:1\n-\n2\n1\nlast:1\nlen:2\n"

rm a.out
exit $RTN
