import numpy as np
from scipy.linalg import expm

# Persamaan pertama: A^3 - 3A^2 - 10A + 12I = 0
A1 = np.polynomial.polynomial.polyroots([12, -10, -3, 1])
print("Solusi untuk persamaan pertama:")
for root in A1:
    if np.all(np.isreal(root)):
        print(root)
        
# Persamaan kedua: A^3 - 10A^2 + 2A - 12I = 0
A2 = np.polynomial.polynomial.polyroots([-12, 2, -10, 1])
print("Solusi untuk persamaan kedua:")
for root in A2:
    if np.all(np.isreal(root)):
        print(root)

# Persamaan ketiga: A^3 + 12A^2 - 2A - 10I = 0
A3 = np.polynomial.polynomial.polyroots([-10, -2, 12, 1])
print("Solusi untuk persamaan ketiga:")
for root in A3:
    if np.all(np.isreal(root)):
        print(root)

# Persamaan keempat: A^3 - 10A^2 + 12A - 10I = 0
A4 = np.polynomial.polynomial.polyroots([-10, 12, -10, 1])
print("Solusi untuk persamaan keempat:")
for root in A4:
    if np.all(np.isreal(root)):
        print(root)
