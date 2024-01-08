

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void file_write(){

    //fstream object can be used for input and output with file
    fstream fio;

    string user_input;

    fio.open("input.txt", ios::trunc | ios::out | ios::in);

    while (fio){

        getline(cin, user_input);

        if (user_input == "-1"){
            break;
        }

        fio << user_input << endl;

    }

    fio.close();

}

void file_read(){
    fstream fio;

    string output;

    fio.open("input.txt", ios::out | ios::in);

    while (fio){

        getline(fio, output);
        cout << output << endl;
    }

    fio.close();
}



int main()
{

    //file_write();
    file_read();

 
    return 0;
}