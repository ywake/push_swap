INCLUDES="-I./includes -I./Libft"
SRCS="./srcs/opt/optimize.c ./srcs/data/stack.c ./srcs/error.c ./tests/opt/test.c"
LIBS="-L. -lft"

echo "> gcc -g $INCLUDES $SRCS $LIBS"
gcc -o push_swap -g $INCLUDES $SRCS ./tests/sharedlib.c $LIBS
if [ $? -ne 0 ]; then
	exit 1
fi

FLG=0

function testfunc() {
	printf "\e[1m%s\n\e[m" "$1"
	diff <(./push_swap $1) <(echo -e $2)
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		./push_swap $1 > /dev/stderr
		FLG=1
	fi
}

printf "\e[1m\e[33m%s\n\e[m" "Should not work"
testfunc "sa sa sa"				"sa\nsa\nsa"
testfunc "rb rb rb"				"rb\nrb\nrb"
testfunc "ra pb ra pb rb"	"ra\npb\nra\npb\nrb"

printf "\e[1m\e[33m%s\n\e[m" "minimal"
testfunc "sa sb"	"ss"
testfunc "ra rb"	"rr"
testfunc "rra rrb"	"rrr"
printf "\e[1m\e[33m%s\n\e[m" "minimal reverse"
testfunc "sb sa"	"ss"
testfunc "rb ra"	"rr"
testfunc "rrb rra"	"rrr"

printf "\e[1m\e[33m%s\n\e[m" "tail"
testfunc "ra sa sb"		"ra\nss"
testfunc "sa ra rb"		"sa\nrr"
testfunc "sa rra rrb"	"sa\nrrr"
printf "\e[1m\e[33m%s\n\e[m" "tail reverse"
testfunc "ra sb sa"		"ra\nss"
testfunc "sa rb ra"		"sa\nrr"
testfunc "sa rrb rra"	"sa\nrrr"

printf "\e[1m\e[33m%s\n\e[m" "head"
testfunc "sa sb ra"		"ss\nra"
testfunc "ra rb sa"		"rr\nsa"
testfunc "rra rrb sa"	"rrr\nsa"
printf "\e[1m\e[33m%s\n\e[m" "head reverse"
testfunc "sb sa ra"		"ss\nra"
testfunc "rb ra sa"		"rr\nsa"
testfunc "rrb rra sa"	"rrr\nsa"

printf "\e[1m\e[33m%s\n\e[m" "middle"
testfunc "ra sa sb ra"		"ra\nss\nra"
testfunc "sa ra rb sa"		"sa\nrr\nsa"
testfunc "sa rra rrb sa"	"sa\nrrr\nsa"
printf "\e[1m\e[33m%s\n\e[m" "middle reverse"
testfunc "ra sb sa ra"		"ra\nss\nra"
testfunc "sa rb ra sa"		"sa\nrr\nsa"
testfunc "sa rrb rra sa"	"sa\nrrr\nsa"

printf "\e[1m\e[33m\e[33m%s\n\e[m" "many xa"
testfunc "sa sb sa"			"sa\nss"
testfunc "ra rb ra ra ra"	"ra\nra\nra\nrr"
testfunc "sa rra rrb rra"	"sa\nrra\nrrr"

printf "\e[1m\e[33m%s\n\e[m" "many xb"
testfunc "sb sb sa"			"sb\nss"
testfunc "rb ra rb rb rb"	"rb\nrb\nrb\nrr"
testfunc "rrb rrb rra sa"	"rrb\nrrr\nsa"

rm leaksout push_swap
exit $FLG
