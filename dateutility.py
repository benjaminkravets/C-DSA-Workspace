import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal
import time
import numpy as np

 
# Using readlines()
file1 = open('badguy.txt', 'r')
Lines = file1.readlines()
 
count = 0
# Strips the newline character
for line in Lines:
    print("| append")
    print("    [| search",line, end='')
    print("     | stats values(ComputerName) as hosts]")