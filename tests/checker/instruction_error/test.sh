make bonus
if [ $? -ne 0 ]; then
	exit 1
fi

cases=(
	"ra rp"		# instruction don’t exist
	"ra \n"		# instruction don’t exist || incorrectly formatted
)

FLG=0
for i in ${!cases[@]};
do
	echo --- "${cases[$i]}" ---
	echo ${cases[$i]} | tr ' ' '\n' | ./checker 4 1 2 3 2>err
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
