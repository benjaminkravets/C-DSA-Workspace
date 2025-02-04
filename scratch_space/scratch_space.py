from itertools import permutations, product
from multiprocessing import Pool


def f(q):
	print(q)



#blue_indexes = [i for i, sublist in enumerate(data) if sublist[0] == 'blue']

#print(blue_indexes)


if __name__ == "__main__":
	data = [['blue', 1],
			['yellow', 2],
			['0010', 2],
			['orange', 5],
			['blue', 7],
			['red', 13]]
	data = [i for i in range(100)]
	print(data)

	with Pool(5) as p:
			p.map(f, data)
	