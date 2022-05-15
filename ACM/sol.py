import decimal
import numpy as np

precision = 20000
decimal.getcontext().prec = precision

E = decimal.Decimal(0)
nFrac=decimal.Decimal(1)
for N in range(1, precision+1):
	E += nFrac
	nFrac /= N

A = [0 for _ in range(10)]
tot = 0
for _ in str(E):
	if _ == '.':
		continue
	A[int(_)] += 1
	tot += 1


print(np.array(A) / tot)
