make bonus
if [ $? -ne 0 ]; then
	exit 1
fi

cases=(
	"./checker \"\""
	# some arguments are not integers
	"./checker 3 2 one 0"
	"./checker 3 2 ++1 0"
	"./checker 3 2 1 --0"
	"./checker 3 2 +-1 0"
	"./checker 3 2 -+1 0"
	# some arguments are bigger than an integer
	"./checker 1 2147483648 0"
	"./checker 1 -2147483649 0"
	# there are duplicates
	"./checker 1 2 3 3"
)

FLG=0

for i in ${!cases[@]};
do
	echo --- "${cases[$i]}" ---
	${cases[$i]} 2>err
	STATUS=$?
	diff err <(echo Error)
	if [ $STATUS -eq 1 ] && [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
done

exit $FLG
