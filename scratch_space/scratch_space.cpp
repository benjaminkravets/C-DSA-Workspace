
#include <algorithm>
#include <iostream>
#include <iterator>
 
using namespace std;

int main()
{
 
    istream_iterator<int> input_iterator(cin);
    
    istream_iterator<int> eos;
 
    ostream_iterator<int> output_iterator(cout, " ");
 
    copy(input_iterator, eos, output_iterator);
 
    return 0;
}