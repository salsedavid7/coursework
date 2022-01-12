import numpy as np
from numpy import linalg

a = np.arange(1,10).reshape(3,3)
b = np.array([3,1,4,2,6,1,2,9,7]).reshape(3,3)
#a.
print("A + B =\n", a+b)
#b.
c = a*b
print("a times b =\n", c)
print("matrix multiplication of a on b:\n", np.matmul(a,b))
#c.
print("Determinants of a:\n", linalg.det(a))
#d.
print("Inverse of b:\n", linalg.inv(b))
#e
print("Eigenvalues of a:\n",linalg.eigvals(a))
