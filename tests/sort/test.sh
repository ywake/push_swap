gen_randint() { python3 -c "import random;print(' '.join(str(num) for num in random.sample(range($2, $3+1), $1)))";}

array=(
	"1"
	"1 2"
	"2 1"
	"1 2 3"
	"2 1 3"
	"-1 1 -3"
	"2 1 4 3"
	"4 1 5 3 2"
	"$(gen_randint 5 -3 3)"
	"$(gen_randint 10 -5 5)"
	"$(gen_randint 100 -50 50)"
	"$(gen_randint 500 -250 250)"
	# "3 5 10 1 4 2 7 6 8 9"
	# "7 16 1 10 15 2 8 4 14 9 11 13 3 6 5 12"
	# "$(jot -r -s " " 100 -2147483648 2147483647)"
	)

for i in ${!array[@]};
do
	echo --- "${array[$i]}" ---
	./push_swap ${array[$i]} > out
	# cat out
	printf "\e[33m%s\n\e[m" $(cat out | wc -l)
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
