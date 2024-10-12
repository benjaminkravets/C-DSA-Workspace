



# def har(func):
#     func()
#     print("Hi")

# @har
# def clean():
#     print("1")
#     return


def generator():
    nums = [1, 2, 3, 4, 5, 6]
    
    squares_it = (n ** 2 for n in nums)

    
    while(next(squares_it)):
        print(squares_it)



if __name__ == "__main__":
    generator()