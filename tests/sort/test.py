import itertools

lst = list(itertools.permutations(range(1, 5)))
str=""
for l in lst:
    for num in l:
        str += f"{num} "
    print(str)
    str=""
