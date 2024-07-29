class NumberFunctor:
   def __init__(self, value):
      self.value = value
        
   def __call__(self, f):
      return f(self.value)
    
def square(x):
   return x * x

functor = NumberFunctor(5)
result = functor(square)
print(result)