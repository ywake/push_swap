INCLUDES="-I./includes -I./Libft"
SRCS="./srcs/input.c ./srcs/error.c ./tests/make_data/test.c"
LIBS="-L. -lft"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -g $INCLUDES $SRCS $LIBS

RTN=0
# tests["./a.out-1-2-3"]="1\n2\n3\n"
function testfunc() {
	echo "$1"
	diff <($1) <(echo -en $2)
	RTN=$(($RTN | $?))
}

testfunc "./a.out 1" "1\n"
testfunc "./a.out 1 2 3" "1\n2\n3\n"
testfunc "./a.out 1 2147483647 3" "1\n2147483647\n3\n"
testfunc "./a.out 1 -2147483648 3" "1\n-2147483648\n3\n"

rm a.out
exit $RTN
