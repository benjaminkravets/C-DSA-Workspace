#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream file_to_write("input_file.txt");

    for (int i = 0; i < 3; i++){
        file_to_write << "Characters for file \n";
    }

    file_to_write.close();

    string read_characters;

    ifstream file_to_read("input_file.txt");

    cout << "Read from file: " << endl;
    
    while (getline(file_to_read, read_characters)){

        cout << read_characters << endl;
    }


}