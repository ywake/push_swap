array=(
	"1"
	"1 2"
	"2 1"
	"1 2 3"
	"2 1 3"
	"4 1 5 3 2"
	)

for i in ${!array[@]};
do
	echo --- "${array[$i]}" ---
	./push_swap ${array[$i]} > out
	cat out
	diff <(cat out | ./checker_Mac ${array[$i]}) <(echo "OK") >/dev/null
	if [ $? -eq 0 ]; then
		printf "\e[32m%s\n\e[m" ">> OK!"
	else
		printf "\e[31m%s\n\e[m" ">> KO!"
		FLG=1
	fi
	rm out
done
exit $FLG
