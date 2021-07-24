FLG=0

array=(
	"./push_swap \"\""
	"./push_swap 1 2 three"
	"./push_swap 1 2 3three"
	"./push_swap 1 2 three3"
	"./push_swap 1 2147483648 2"
	"./push_swap 1 -2147483649 2"
	"./push_swap 1 2147483649000 2"
	"./push_swap 1 2 3 3"
	"./push_swap 1 +-2 3"
	"./push_swap 1 -+2 3"
	"./push_swap 1 ++2 3"
	"./push_swap 1 --2 3"
	)

make leak
if [ $? -ne 0 ]; then
	exit 1
fi

# for i in $(seq 1 ${#array[@]});
for i in ${!array[@]};
do
	echo "--- [$i] ${array[$i]} ---"
	# $REPO_ROOT/${array[$i]}
	${array[$i]}
	if [ $? -eq 1 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
done
rm -f leaksout
exit $FLG
