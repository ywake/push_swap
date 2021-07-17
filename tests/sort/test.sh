gen_randint() { python3 -c "import random;print(' '.join(str(num) for num in random.sample(range($2, $3+1), $1)))";}

array=(
	"1"
	"1 2"
	"2 1"
	"1 2 3"
	"1 3 2"
	"2 1 3"
	"3 1 2"
	"2 3 1"
	"3 2 1"
	"2 1 4 3"
	"4 1 5 3 2"
	"5 4 3 2 1"
	"$(gen_randint 5 -3 3)"
	"9 8 7 6 5 4 3 2 1"
	"7 3 0 2 9 1 10 4 5 8"
	"$(gen_randint 10 -5 5)"
	"$(gen_randint 10 0 10)"
	"$(gen_randint 100 -50 50)"
	# "-2 39 -27 26 -35 17 -15 -29 -11 -26 44 13 46 4 -22 42 -49 30 -4 20 -19 22 48 49 14 -20 -41 -14 -43 -23 33 -32 -34 31 -13 -37 15 6 40 24 -7 -17 27 8 18 -1 -25 -39 47 5 16 0 -12 -45 -18 35 25 3 -6 -28 -36 10 -5 -33 -30 43 19 -3 2 21 41 -8 -42 38 -50 9 -31 -24 11 23 29 -40 -44" #595->562->499
	"14 -27 20 -28 -11 -10 40 42 -7 -9 21 -43 -14 -40 35 -18 34 39 24 -22 2 28 -33 -32 36 18 -50 -2 48 -19 -41 29 38 -24 -29 25 -16 -15 19 37 -8 -3 17 13 -35 -44 -26 -5 -4 27 3 33 50 -36 43 -45 16 49 -49 47 -47 41 -12 46 45 12 8 44 -38 10 -37 -23 -6 -13 22 7 -34 -20 32 -31 -48 31 15 5 6 -17 1 11 -1 26 4 30 -21 -46 -30 23 -39 -42 9 0" # 722->->676
	"$(seq 1 100 | sort -rn | xargs echo)" #->704->696
	"$(seq 1 100 | xargs echo)"
	"$(gen_randint 500 -250 250)"
	"$(seq 1 500 | sort -rn | xargs echo)" #->->4507
	)

make test

for i in ${!array[@]};
do
	echo --- "${array[$i]}" ---
	./push_swap ${array[$i]} > out
	# cat out > out100
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
