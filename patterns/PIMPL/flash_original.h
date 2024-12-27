#include <iostream>

// flash.hpp header file

// third_party.h // large third part inclusion

// traditional class- any file that includes this file will
// need to recompile if the definition of third_pary_obj changes. This file also 
// reveals internal details like the use of the third_pary_obj-this is also not flexible;
// the code is tied to third_party.h which can change, breaking this code.

class Flash
{
public:
    Flash() = default;
    int read(int addr, int byte_count, char * read_buffer);

private:
    //third_party_obj obj_0;
    int size;
    char jedec_id;
};