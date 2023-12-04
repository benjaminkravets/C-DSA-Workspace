import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal
import time
import numpy as np


def calculate_stats(x):
    mean = np.mean(x)
    median = np.median(x)
    std_dev = np.std(x)
    return mean, median, std_dev

data = np.random.randn(1000)
vectorized_calculate_stats = np.vectorize(calculate_stats)
stats = vectorized_calculate_stats(data)

print(stats)




""" 
print("   _______________ __________     __ __ ________ ")
print("  / ____/  _/ ___// ____/ __ \   / //_//  _/ __ \\")
print(" / /    / / \__ \/ /   / / / /  / ,<   / // / / /")
print("/ /____/ / ___/ / /___/ /_/ /  / /| |_/ // /_/ / ")
print("\____/___//____/\____/\____/  /_/ |_/___/_____/  ")

 """