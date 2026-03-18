import my_module
import argparse
import sys


def here():
    print("hi")

def strings_bytes():
    #raw strings:
    print("C:\\Users\\bkravets")
    print(r"C:\\Users\\bkravets")

    #mutliline string:
    a = """a
            a"""
    print(a)
    
    #string literals can be concatenated or multiplied:
    print(3 * 'a' + 'b' 'c')
    
    #strings can be indexed
    word = '321'
    print(word[-2:-1] + ' ' + word[2:])
    
    #strings are immutable
    #word[0] = 'i' #no
    
    #get length
    print("length",len('111'))

def lists():
    squares = [1, 4, 9] + [16, 25]
    squares.append(36)
    squares[0:1] = []
    print(squares)
    
    n = [[3.14],squares]
    print(n, n[1][1], n[::-1])
    
def basics():
    """
    Docstrings should be a short, concise summary of an object's purpose, beginning with a capitol and ending with a period.
    
    If more description is needed, it should follow the summary and be seperated by blank line. This is accessible as basics.__doc__
    """
    #numbers, strings, and tuples are immutable, lists, dicts, sets are mutable
    #names are always references; here assigning a variable using another makes it a reference to the original
    a = 1   #a referes to a '1' object in memory
    b = a   #this copies the reference, so b refers to the same '1' object in memory
    print(id(a) == id(b), a, b)
    a = 2   #a now refers to a different object in memory '2'
    print(id(a) == id(b), a, b)

    #similar to above, but lists are mutable- append() modifies the existing list object in memory, it doesn't create a new one
    c = [1, 2, 3]
    d = c
    print(id(c) == id(d), d, c)
    c.append(4) 
    print(id(c) == id(d), d, c)

    #dictionaries store data in kv pairs
    thisdict = {
        "make": "Ford",
        "year": "2025"
    }
    
    print(thisdict["make"])
    
    #in keyword:
    if 1 in [1, 2, 3]:
        print("1's there!")
        
    if 5 not in [1, 2, 3]:
        print("5's not!")
        
    #check if two objects are the same (in memory, not like == which checks equality)
    
    print([0,10] is [0,10], a is a)
    print([0,10] is not [0,10])
    
    #chain comparisons, here 2 comparisons are ANDd
    print(1 < 2 == 2)
    
    #Boolean and, or, and not are avialable with lower priorities than comparison operators. NOT has the highest priority, OR is lowest
    print(1 and not 0 or 1) #==(1 and (not 0)) or 1
    
    #AND and OR are short-circuit operators. If A and C are true but B is false, A AND B AND C doesn't evaluate C.
    print('' or '' or 'hi!')
    
    #the walrus operator := allows assignment within an expression. here n is assigned and used instead of using n = len(d) above the comparison
    d = 'abcde'
    if (n := len(d) > 2): 
        print('too long')


def built_in_functions():
    #range() is an iterable object (created for objects expecting something they can obtain successive items from). so is "for"
    for i in range(2,4): print(i)
    print(list(range(10, 20, 2)), sum(range(4)))

def control_flow():
    a, b = 0, 1 #multiple assignment
    while a < 3:
        print(a)
        a, b = b, a+b

    if 2 < 1:
        print('true0')
    elif 3 < 2:
        print('true1')
    else:
        print('false')
        
    #for iterates over the items of a sequence (list or string)
    words = ['a', 'bb']
    for w in words:
        print(w, len(w))
        
    #break breaks out of the innermost enclosing for or while loop:
    for n in range(1, 10):
        print(n, " ", end='')
        for x in range(n):
            print(x, end='')
            if x > 4: 
                break
        print()
    
    #continue continues with next loop iteration
    for num in range(2, 10):
        if num % 2 == 0:
            print("even", num)
            continue
        print("odd", num)

    #else can catch an inner break:
    for i in range(5):
        for x in range(5):
            if 1 == 2: 
                print("break")
                break
        else:
            print("no break!")
            
    #pass does nothing, it's for when a statement is required but no action is needed. Here, wait for Ctrl-C
    #while True:
    #    pass
    
    status = 3
    status = (0, 1)
    match status:
        case (0, x): #match a tuple and bind a value from the subject
            print("match 0", x)
        case 1:
            print("match 1")
        case 2 | 3:
            print("match 2 or 3")
        case _:
            print("everything else")

def pass_by_value(x):
    x += 1
    print(x)
    
varx = 1
#only prompt is mandatory, the other arguments are optional.
#could be called with:
#functions("do you want to?")
#functions("do you want to?", 2)
#functions("do you want to?", 2, "oh, come on!")
#can also be called with keyword arguments (kwars=value):
#functions(prompt="do you?")

def functions(prompt, retries=4, reminder="please try again"):
    """should have a docstring"""
    #variable assignments in a function are stored in the function's symbol table
    a = 1

    #fails
    #print(varx)
    
    #this refers to the inner (local symbol table) varx, not the global symbol table, the former matches first
    varx = 2
    print(varx)
    
    #to assign a value to an outer function variable or global, use global (for referencing this isn't needed)
    #global varx
    
    #parameters are passed by value, but if b was a list, pass_by_value could .append() and modify it
    b = 99
    pass_by_value(b)
    print(b)
    
    #* is hte iterable unpacking operator (splat) and passes each list item as a seperate positional argument
    print([1,2,3], *[1,2,3], 1, 2, 3)
    
#arguments are positional (only), positional or keyword, or keyword (only), whether arguments have to be passed as a certain kind can be enforced with * and /:
#def f(pos1, pos2, /, pos_or_kwd, *, kwd1, kwd2):
#extra arguments can be passed, either unnamed (arguments *) or named (kwargs **)
#args is a tuple, keywords is a dictionary
def functions2(make, *arguments, **keywords):
    print(make)
    for i in arguments:
        print(i)
    for kw in keywords:
        print(kw, ":", keywords[kw])
        
    #arguments in a list or tuple can be unpacked at call:
    args = [3,6]
    print(list(range(*args)))

#it is possible to pass a lambda as an argument too
def make_incrementor():
    return lambda x: x + 1

#Annotations suggest but don't enforce argument, return, and variable types (type hinting)
def functions3(a: str, b: int) -> complex:
    z: int = 10
    
    f = make_incrementor()
    print(f(2))
    
def lists():
    
    a = [1, 2, 3]
    
    a.append(4) ; print(a) #add to end
    a.extend([1,2,3]) ; print(a) #add iterable to end
    a.insert(0, 1) ; print(a) #insert 1 at position 0 (front)
    a.remove(1) ; print(a) #remove the first instance of 0 in the list
    b = a.pop(2) ; print(a, b) #remove and return the item at index 2
    a.clear() ; print(a) #remove all items
    
    a = [1, 5, 2, 4, 5, 2]
    b = a.index(2) ; print(a, b) #get index of first occurence of 2
    b = a.count(2) ; print(b) #get how many times 2 occurs
    a.sort() ; print(a) #sort
    a.reverse() ; print(a) #reverse
    
    c = [1,2,3]
    d = c.copy() ; print(c, d) #without copy, d.reverse() modifies original list
    d.reverse() ; print(c, d)
    
    #a LIFO can be implemented with append() and pop() (without an index)
    #lists can be dequeus but this is inefficient, use collections.deque
    
    #list comprehensions are a concise way to create lists.
    squares = []
    for x in range(10): squares.append(x**2)
    
    #That creates an extra variable x. This is also possible:
    squares = list(map(lambda x: x**2, range(10)))
    
    #Best:
    squares = [x**2 for x in range(10)]
    
    #list comprehension applies to nested and nd-array lists.
    
    #del removes items given an index/range
    e = [1, 2, 3]
    del e[2] ; print(e)
    #del e ; print(e)
    
    #list unpacking:
    d, e, f = [1, "hi", 3.4] ; print(d, e, f)

    
def tuples():
    #tuples are a few comma sepearted values
    a = 1, "hi", 3.4 ; print(a)
    #tuples are immutable
    #a[0] = 1 #no
    
    #Tuples are used for heterogeneous data by unpacking, lists are mutable, typically homogeneous, and accessible by iteration
    #tuples can have 0 and/or 1 elements
    b = ()
    c = 'hi',
    
    #tuple unpacking:
    d, e, f = a ; print(d, e, f)
    
def sets():
    #sets are unordered collections with no duplicates. Can be used for membership testing and eliminating duplicates. 
    
    a = {'apple', 'orange', 'apple', 'pear', 'orange', 'bannana'} ; print(a)
    print('apple' in a)
    
    b = set('abracadabra') ; print(b)
    c = set('alacazam') ; print(c)
    
    print(b - c)
    print(b | c) #or
    print(b & c) #and
    print(b ^ c) #in one but not both
    
    #list comprehension is also possible

def dictionaries():
    #kv pairs indexed by keys, not numbers. keys can be any immutable type like strings or numbers
    #main operations are inserting, del, and searching on a key
    
    a = {'jack' : 4098, 'sape': 4139} ; print(a)
    a['jack'] = 1 ; print(a['jack'])
    #d[key] will error if the key DNE, get() will return a None
    print(a.get('irv'))
    del a['jack'] ; print(a)
    print(list(a))
    print('sape' in a)
    
    #dict() can create a dictionary from kv-pair sequences
    b = dict([('beans', 1), ('cornbread', 2), ('grits', 3)]) ; print(b)
    
    #list comprehension still applies
    
    #keys can even be specified by kw args
    c = dict(oatmeal=1,limas=2,peas=3) ; print(c)
    
    #get dictionary keys and values using items()
    for k, v in c.items(): print(k, v)
    
def sequences():
    
    #enumerate gets the index and value for any sequence:
    for i, v in enumerate(['tic', 'tac', 'toe']):
        print(i, v)
        
    #zip can iterate over 2 or more sequences:
    d = [1, 2, 3]
    e = [4, 5, 6]
    for f, g in zip(d, e):
        print(f, g)
    
    #present sequency in reverse:
    for i in reversed(range(1, 10, 2)):
        print(i)
    
    #sort unique elements in a set:
    for i in sorted(set('bacdabcjaskjd')):
        print(i)
        
    #it's usually simpler/safer to create a new list instaeda of changing one while looping over it
    
    #here, 1 and 1 are evaluated, then 2 and 2, then finally 3 and 4 which matches
    print((1, 2, 3) < (1, 2, 4))
    
if __name__ == "__main__":
    #this doc covers 1-5 of the Python tutorial
    #strings_bytes()
    #basics()
    #lists()
    #built_in_functions()
    #control_flow()
    #functions('a')
    #functions2('Toyota', 'arg1', 'arg2', arg3='arg3', arg4='arg4')
    #functions3(1, 1)
    #lists()
    #tuples()
    #sets()
    #dictionaries()
    #sequences()
