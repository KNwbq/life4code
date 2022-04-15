s = str(input())
q = int(input())

while q:
	ss = input()
	t, k = ss.split(' ')

	t = int(t)
	k = int(k) - 1
	buff = pow(2, t)
	len = buff
	pos = k // (buff)
	c = s[pos]
	k = k % (buff)

	if t == 0:
		q -= 1
		print(c)
		continue
	t = max(t-1, 0)

	while len > 1 and t > 0:
		if c == "A":
			if k == 0:
				c = "B"
			else:
				c = "C"
		if c == "B":
			if k == 0:
				c = "C"
			else:
				c = "A"
		if c == "C":
			if k == 0:
				c = "A"
			else:
				c = "B"

		k = k % (int(buff))
		buff /= 2
		t = max(t-1, 0)
		len /= 2

	if c == "A":
		if k == 0:
			ans = "B"
		else:
			ans = "C"
	if c == "B":
		if k == 0:
			ans = "C"
		else:
			ans = "A"
	if c == "C":
		if k == 0:
			ans = "A"
		else:
			ans = "B"
	print(ans)
	q -= 1