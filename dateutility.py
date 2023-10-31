import pyautogui as pag
import ctypes

print(pag.size())



submit_button = None
while submit_button is None:
    submit_button = pag.locateOnScreen(image="target.png", confidence=.7)

print(submit_button)


pag.moveTo(submit_button, duration=1)
#pag.click()
