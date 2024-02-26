using namespace std;

#include <iostream>
#include <unordered_set>

void print_unordered_set(unordered_multiset<int> tmp){

    for(unordered_multiset<int>::iterator itr = tmp.begin(); itr != tmp.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}



int main(){

    unordered_multiset<int> my_set = {1, 2, 3, 4, 5};

    print_unordered_set(my_set);

    //can insert duplicate items
    my_set.insert(1);
    my_set.insert(4);

    cout << "Can insert duplicates: " << endl;

    print_unordered_set(my_set);

    //insert many ints to demonstrate buckets
    for (int i = 0; i < 1000; i++){

        my_set.insert((rand() & 100));
    }

    //print_unordered_set(my_set);
    cout << "Size: " << my_set.size() << endl;
    cout << "Load factor: " << my_set.load_factor() << endl;
    cout << "Bucket count: " << my_set.bucket_count() << endl;


    unordered_set<int> unique_set(my_set.begin(), my_set.end());

    cout << "Unique elements: " << unique_set.size() << endl;



}