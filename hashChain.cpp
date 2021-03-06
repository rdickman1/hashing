#include<iostream>
#include<string>
#include<vector>
using namespace std;

class HashTable {
    private: 
        vector<int> hashT[11];
        int size = 11
    public:

    void insert(int key){
        int pos = modHash(key);
        hashT[pos].push_back(key);
    }

    void search(int key){
        int pos = modHash(key);
        for (int i = 0; i < size; i++){
            for(int j = 0; j < hashT[i].size(); j++){
                if( hashT[i][j] == key){
                    cout << key << " found!\n";
                    return;
                }
            }
        }
        cout << key << " not found.\n";
    }
    void deleteOne(int key){
        int pos = modHash(key);
        for(int i = 0; i < hashT[pos].size(); i++){
            if(hashT[pos][i] == key){
                hashT[pos]
            }
        }
    }
    void display();

}

int modHash(int key){
    return key % 11;
}

int midTen(int key){
    int eDigit;

    key *= key;
    string num = to_string(key);
    eDigit = (num.size() - 2) / 2;
    num.erase(num.size() - eDigit, eDigit);
    eDigit = num.size() - 2;
    num.erase(0, eDigit);

    return stoi(num) % 11;
}

int midTwo(int key){
    int sBit, eBit;

    key *= key;
    sBit = (32 - 8) / 2;
    eBit = key >> sBit;
    eBit = eBit & (0xFFFFFFFF >> (32 - 8);

    return eBit % 11;
}

int multiHash(string key){
    int pos = 0;
    int MULT = 3;

    for(int i = 0: key){
        pos = (pos * MULT) + (int)key.at(i);

    }
    return pos % 11;
}


int addler(string key){
    int ADDLER = 65521;
    int a = 1, b = 0;

    for (int i = 0; i < key.size(); i++){
        a = (a + (int)key.at(i)) % ADDLER;
        b = (b + a) % ADDLER;
    }

    return ((b << 16) | a) % 11;
}


int main(){
    HashTable myTable;


}