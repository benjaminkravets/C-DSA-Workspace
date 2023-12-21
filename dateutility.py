import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal
import time
import numpy as np

 
# Using readlines()
file1 = open('curated.txt', 'r')
Lines = file1.readlines()
 
count = 0
# Strips the newline character
for i, line in enumerate(Lines):

    if i == 0:
        print(line, end='')
        print("     | stats values(ComputerName) as hosts")
    else:
        print("| append")
        print("    [| search",line, end='')
        print("     | stats values(ComputerName) as hosts]")

print("| stats count by hosts")