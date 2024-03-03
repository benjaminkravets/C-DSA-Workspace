
#include <algorithm>
#include <iostream>
#include <iterator>
#include <getopt.h>


using namespace std;

int main()
{
    //iterator for user input
    istream_iterator<int> input_iterator(cin);
    
    //end of user input (no space)
    istream_iterator<int> input_end;

    //output iterator to take input, delimited by spaces
    ostream_iterator<int> output_iterator(cout, ",");
 
    //copy input to output
    copy(input_iterator, input_end, output_iterator);
 
    return 0;
}