INCLUDES="-I./includes -I./Libft"
SRCS="./srcs/opt/rm_nonsense.c ./srcs/data/stack.c ./srcs/error.c ./tests/rm_nonsense/test.c"
LIBS="-L. -lft"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -o push_swap -g $INCLUDES $SRCS ./tests/sharedlib.c $LIBS

FLG=0

function testfunc() {
	printf "\e[1m%s\n\e[m" "$1"
	diff <(./push_swap $1) <(echo -en $2)
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		./push_swap $1 > /dev/stderr
		FLG=1
	fi
}

printf "\e[1m\e[33m%s\n\e[m" "Should not work"
testfunc "pa pa pa"				"pa\npa\npa\n"
testfunc "pb pb pb"				"pb\npb\npb\n"
testfunc "pa ra rb pb rra rrb"	"pa\nra\nrb\npb\nrra\nrrb\n"

printf "\e[1m\e[33m%s\n\e[m" "minimal"
testfunc "pa pb"	""
testfunc "ra rra"	""
testfunc "rb rrb"	""
printf "\e[1m\e[33m%s\n\e[m" "minimal reverse"
testfunc "pb pa"	""
testfunc "rra ra"	""
testfunc "rrb rb"	""

printf "\e[1m\e[33m%s\n\e[m" "tail"
testfunc "ra pa pb"		"ra\n"
testfunc "sa ra rra"	"sa\n"
testfunc "sa rb rrb"	"sa\n"
printf "\e[1m\e[33m%s\n\e[m" "tail reverse"
testfunc "ra pb pa"		"ra\n"
testfunc "sa rra ra"	"sa\n"
testfunc "sa rrb rb"	"sa\n"

printf "\e[1m\e[33m%s\n\e[m" "head"
testfunc "pa pb ra"		"ra\n"
testfunc "ra rra sa"	"sa\n"
testfunc "rb rrb sa"	"sa\n"
printf "\e[1m\e[33m%s\n\e[m" "head reverse"
testfunc "pb pa ra"		"ra\n"
testfunc "rra ra sa"	"sa\n"
testfunc "rrb rb sa"	"sa\n"

printf "\e[1m\e[33m%s\n\e[m" "middle"
testfunc "ra pa pb ra"		"ra\nra\n"
testfunc "sa ra rra sa"		"sa\nsa\n"
testfunc "sa rb rrb sa"		"sa\nsa\n"
printf "\e[1m\e[33m%s\n\e[m" "middle reverse"
testfunc "ra pb pa ra"		"ra\nra\n"
testfunc "sa rra ra sa"		"sa\nsa\n"
testfunc "sa rrb rb sa"		"sa\nsa\n"

# rm leaksout push_swap
exit $FLG
