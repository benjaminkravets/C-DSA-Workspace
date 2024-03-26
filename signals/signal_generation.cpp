#include <iostream>
#include <csignal>

using namespace std;

void handle_signal(int signal_id){

    cout << "Interrupted with " << signal_id << endl;

    //exit with signal; it is possible to return and continue exeucution
    exit(signal_id);


}


int main(){
    //register signal to handler
    signal(SIGFPE, handle_signal);

    //raise this signal
    raise(SIGFPE);
}