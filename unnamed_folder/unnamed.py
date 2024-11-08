



# def har(func):
#     func()
#     print("Hi")

# @har
# def clean():
#     print("1")
#     return


#1. closures
def outer_function():
    a = 1
    def inner_function():
        return a
    return inner_function

def get_closure():
    a = outer_function()
    print(a())


def generators_vs_list_comprehension():

    nums = [1, 2, 3, 4, 5, 6]
    
    #lazy evaluated
    squares_iterator = (n ** 2 for n in nums)

    for i in squares_iterator:
        print(i)

    #eager evaluated
    squares_list = [n ** 2 for n in nums]

    print()

    for i in squares_list:
        print(i)

if __name__ == "__main__":


    get_closure()
    #generators_vs_list_comprehension()

    