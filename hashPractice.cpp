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

int modHash(int key){
    return key % 11;
}

// Mid-square base 10

int midTen(int key){

    int eDigit;

    key *= key;
    string num = to_string(key);
    
    eDigit = (num.size()-2) / 2;

    num.erase(num.size()-eDigit, eDigit);

    eDigit = num.size() - 2;

    num.erase(0, eDigit);

    return stoi(num) % 11;
}

// Mid Square base 2

int modTwo(int key){

    int eBit, sBit;

    key *= key;
    sBit = (32 - 8) / 2;
    eBit = key >> sBit;
    eBit = eBit & (0xFFFFFFFF >> (32 - 8));

    return eBit % 11;

}

// Multiplicative String

multiHash(string key){
    int pos = 0;

    for()
}


void insert(vector<Item>& hashTable, int key){
    int pos = modTwo(key);
    for (int i = 0; i < hashTable.size(); i++){
        if(hashTable.at(pos).emptyAfterRemoval == true || hashTable.at(pos).emptySinceStart == true){
            hashTable.at(pos).value = key;
            hashTable.at(pos).emptySinceStart = false;
            hashTable.at(pos).emptyAfterRemoval = false;
            cout << key << " was inserted.\n";
            return;
        }
        
        //******* Collision Strat ********
        // linear Probe
        pos = (pos + 1) % hashTable.size();

        // Quadractic Probe
        //int c1 = 2, c2 = 1;
        //pos = (modHash(key) + (c1 * i) + (c2 * i * i)) % hashTable.size();

        // Double Hash
        //pos = (modHash(key) + i * ) % hashTable.size();
    }

    cout << "Could not Insert.\n";
}

void search(vector<Item> hashTable, int key){
    int pos = modTwo(key);
    for (int i = 0; i < hashTable.size(); i++){
        if(key == hashTable.at(pos).value){
            cout << key << " was found!\n";
            return;
        }
        if(hashTable.at(pos).emptySinceStart == true){
            cout << key << " not found.\n";
            return;
        }

        // Collision Strat
        // linear probe
        pos = (pos + 1) % hashTable.size();

        // Quadratic Probe
        //int c1 = 3, c2 = 1;
        //pos = (modHash(key) + (c1 * i) + (c2 * i * i)) % hashTable.size(); 
    }

    cout << key << "not found.\n";
}

void deleteOne(vector<Item>& hashTable, int key){
    int pos = modTwo(key);
    for (int i = 0; i < hashTable.size(); i++){
        if (key == hashTable.at(pos).value){
            hashTable.at(pos).value = -1;
            hashTable.at(pos).emptyAfterRemoval = true;
            cout << key << " deleted.\n";
            return;
        }
        if(hashTable.at(pos).emptySinceStart == true){
            cout << key << " not found.\n";
            return;
        }

        // linear probe
        pos = (pos + 1) % hashTable.size();

        // Quadratic Probe
        //int c1 = 6, c2 = 55;
        //pos = (modHash(key) + c1 * i + c2 * i * i) % hashTable.size();

        // Double Hash
        //pos = (modHash(key) + i * ) % hashTable.size();
    }
    cout << key << " not found.\n";
}

void display(vector<Item> hashTable){
    for(int i = 0; i < hashTable.size(); i++){
        cout << i << "|\t";
        if(hashTable.at(i).emptySinceStart == true || hashTable.at(i).emptyAfterRemoval == true){
            
        }
        else{
            cout << hashTable.at(i).value;
        }
        cout << endl;
    }
}

void hashMenu(vector<Item>& hashTable){
    int choice, userSelect;
    do{
        cout << "Please choose from the following options:\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display Table\n5. Quit\n";
        cout << "Option: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter a number to insert: ";
                cin >> userSelect;
                insert(hashTable, userSelect);
                break;
            case 2:
                cout << "Enter a nuber to search for: ";
                cin >> userSelect;
                search(hashTable, userSelect);
                break;
            case 3:
                //delete
                break;
            case 4:
                display(hashTable);
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


int main(){

    int N = 11;
    vector<Item> hashTable(11);

    hashMenu(hashTable);

    return 0;
}