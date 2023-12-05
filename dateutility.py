import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal
import time
import numpy as np

class Node:
   def __init__(self, dataval=None):
      self.dataval = dataval
      self.nextval = None

class SLinkedList:
   def __init__(self):
      self.headval = None

   def listprint(self):
      printval = self.headval
      while printval is not None:
         print (printval.dataval)
         printval = printval.nextval

list = SLinkedList()
list.headval = Node("Mon")
e2 = Node("Tue")
e3 = Node("Wed")

# Link first Node to second node
list.headval.nextval = e2

# Link second Node to third node
e2.nextval = e3

list.listprint()



""" 
print("   _______________ __________     __ __ ________ ")
print("  / ____/  _/ ___// ____/ __ \   / //_//  _/ __ \\")
print(" / /    / / \__ \/ /   / / / /  / ,<   / // / / /")
print("/ /____/ / ___/ / /___/ /_/ /  / /| |_/ // /_/ / ")
print("\____/___//____/\____/\____/  /_/ |_/___/_____/  ")

 """