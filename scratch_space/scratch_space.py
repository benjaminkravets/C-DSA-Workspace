from itertools import permutations, product
from multiprocessing import Pool


import matplotlib.pyplot as plt

# Sample data
x = [1, 2, 3, 4, 5]
y = [1, 4, 9, 16, 25]

plt.plot(x, y)

# Add a vertical line at x=3
plt.axvline(x=3, color='r', linestyle='--')

plt.show()
