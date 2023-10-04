import ray
import random
import time
import math
from fractions import Fraction

# Let's start Ray
ray.init(address='auto')


import numpy as np
import time

import ray
from ray.util.multiprocessing import Pool
pool = Pool()

def f(x):
    time.sleep(1)
    return 1.5 * 2 - x

def my_func_par(large_list):
    pool.map(f, large_list)

def my_func_seq(large_list):
    [f(i) for i in large_list]

my_list = np.arange(1, 10000)

s = time.time()
my_func_par(my_list)
print('Parallel time: ' + str(time.time() - s))

s = time.time()
my_func_seq(my_list)
print('Sequential time: ' + str(time.time() - s))