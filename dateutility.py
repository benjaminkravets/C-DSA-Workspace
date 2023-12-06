import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal
import time
import numpy as np

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
   
        
if __name__ == "__main__":

    a = Node(1)
    b = Node(3)
    c = Node(5)
    a.next, b.next = b, c

    for i in [a,b,c]:
        print(i.data)

    
""" 
print("   _______________ __________     __ __ ________ ")
print("  / ____/  _/ ___// ____/ __ \   / //_//  _/ __ \\")
print(" / /    / / \__ \/ /   / / / /  / ,<   / // / / /")
print("/ /____/ / ___/ / /___/ /_/ /  / /| |_/ // /_/ / ")
print("\____/___//____/\____/\____/  /_/ |_/___/_____/  ")

 """