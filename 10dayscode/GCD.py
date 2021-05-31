def gcd(a,b):
	if a <= 0 or b <= 0:
		return 0
	small = min(a,b)
	big = max(a,b)

	if big%small == 0: 
		return small
	else:
		# recursive call
		return gcd(small, big%small)

a = int(input())
b = int(input())

print(gcd(a,b))