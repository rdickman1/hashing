// Practice for building a hash table with different functions
//   and different collision strats

#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Item{
    int value;
    bool emptySinceStart = true;
    bool emptyAfterRemoval = false;
};


// Modulo hash function

int modHash(int key, int size){
    return key % size;
}

// Mid-square base 10

int midTen(int key, int size, int R){

    int eDigit;

    key *= key;
    string num = to_string(key);
    
    eDigit = (num.size()-R) / 2;

    num.erase(num.size()-eDigit, eDigit);

    eDigit = num.size() - R;

    num.erase(0, eDigit);

    return stoi(num) % size;
}

void hashMenu(){
    int choice;
    do{
        cout << "Please choose from the following options:\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display Table\n5. Quit\n";
        cout << "Option: ";
        cin >> choice;

        switch(choice){
            case 1:
                //insert
                break;
            case 2:
                //search
                break;
            case 3:
                //delete
                break;
            case 4:
                //display
                break;
            case 5:
                cout << "Quiting...\n";
                break;
            default:
                cout << "Invailid Selection\n";
                break;
        }
    }while(choice != 5);
}

void insert(vector<Item>& hashTable, int key, int value){

}

int main(){

    int N = 11;
    vector<Item> hashTable(11);

    hashMenu();

    return 0;
}