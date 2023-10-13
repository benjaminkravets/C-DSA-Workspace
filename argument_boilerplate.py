import argparse
import sys
import datetime

def func1(name):
	print("func1 called",name)
	
def func2(date, qball, color=0):
	print("func2 called",date, qball, color)


if __name__=="__main__":
	parser = argparse.ArgumentParser()
	
	parser.add_argument('-a','--action', required=True, choices=["func1", "func2"], help="Action to take")

	parser.add_argument('-d', '--date', nargs=1, help='Date')
	parser.add_argument('-q', '--qball', nargs=1, help='Arguments')
	parser.add_argument('-c', '--color', nargs=1, type=int, help='Arguments')
	

	args = parser.parse_args()

	if args.action == "func1":
		func1(args.qball)
		
	elif args.action == "func2":
		if args.date is None:
			parser.error("With this function, a date is required")
		if args.qball is None:
			parser.error("With this function, a qball is required")
		func2(args.date, args.qball, args.color)