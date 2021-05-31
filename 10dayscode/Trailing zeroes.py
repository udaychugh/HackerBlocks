from math import floor

num = int(input())

occ, i = 0, 1
flag = True

while flag:
    eq_part = floor(num/5**i)

    #condition to get out of the loop
    if eq_part == 0:
        flag = False
    else:
        occ += eq_part
        i += 1

print(occ)