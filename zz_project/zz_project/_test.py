from my_module import module_function_add

def test_adder():
    result = module_function_add(1,1)
    assert result == 2
    
class TestClass:
    def test_positives(self):
        assert module_function_add(1,2) == 3
    def test_negatives(self):
        assert module_function_add(-1,-1) == -2