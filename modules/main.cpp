#include <iostream>

// header files are to inform the compiler about types, functions, etc- they contain declarations.

// headers need reparsed for each tranlation unit that uses them, modules don't 
// modules don't automatically expose macros and using declarations to the importing translation unit
// header file inclusion is handled by the preprocessor/linker. some dependency errors happend during preprocessing, some during linking. modules are a language feature, so dependency management happens during compilation
// #includes for headers may need to be in a specific order for header files, imports for modules don't need to be
import flash_module;

int main()
{

    flash_namespace::flash_init();
    return 0;
}