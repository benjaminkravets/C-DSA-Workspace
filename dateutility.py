import pyautogui as pag
import ctypes
import pyperclip
import numbers
import decimal

#curlay = pyperclip.paste()

def is_number(curlay):
    try:
        tmp = float(curlay)
        print('The variable a number')
    except:
        print('The variable is not a number')


is_number(' ')
is_number(1)
is_number(1.2)