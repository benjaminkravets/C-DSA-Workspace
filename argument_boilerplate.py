import argparse
import sys

def func1(name):
	print("func1 called",name)
	
def func2(name, date):
	print("func2 called",name,date)

parser = argparse.ArgumentParser()

parser.add_argument('-n', '--name', required=True, help='Arguments')
parser.add_argument('-d', '--date', help='Date')
parser.add_argument('-a','--action', required=True, choices=["func1", "func2"], help="Action to take")

args = parser.parse_args()

if args.action == "func1":
	func1(args.name)
	
elif args.action == "func2":
	if args.date is None:
		parser.error("With this function, a date is required")
	func2(args.name,args.date)
