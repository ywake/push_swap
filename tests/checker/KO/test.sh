if [ $(uname) == "Linux" ]; then
	CHECKER="./checker_linux"
else
	CHECKER="./checker_Mac"
fi

make bonus_leak
if [ $? -ne 0 ]; then
	exit 1
fi

cases=(
	"pb"		# Sorted, but stackB is remain.
	"sa pb"		# Not sorted, and stackB is remain.
	"pb pa"		# Not sorted
	# "ra rp"		# instruction don’t exist
	# "ra \n"		# instruction don’t exist || incorrectly formatted
)

FLG=0
for i in ${!cases[@]};
do
	echo --- "${cases[$i]}" ---
	echo ${cases[$i]} | tr ' ' '\n' | ./checker 4 1 2 3 > out
	STATUS=$?
	diff <(cat out) <(echo ${cases[$i]} | tr ' ' '\n' | $CHECKER 4 1 2 3)
	if [ $? -eq 0 ] && [ $STATUS -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
	rm -f out
done

rm -f leaksout
exit $FLG
