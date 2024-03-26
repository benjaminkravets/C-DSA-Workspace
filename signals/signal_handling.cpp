#include <iostream>
#include <csignal>

using namespace std;

//handle signal
void handle_signal(int signal_id){

    cout << "Interrupted with " << signal_id << endl;

    //exit with signal; it is possible to return and continue exeucution
    if (signal_id == 2){
        exit(signal_id);
    } else return;

}

void gen_mem_fault(){
    //c based way to generate a mem fault by passing null pointer to fputc
    char *p = 0;
    fputc(*p, stdout);
}


int main(){

    //register the attention signal to be handled by the handler function
    //SIGINT (2) is for interaction from the user to "interrupt" the program.
    signal(SIGINT, handle_signal);
    signal(SIGSEGV, handle_signal);

    //Will generate interrupt 11 until user stopc program with ctrl-c
    gen_mem_fault();

    return 0;
}