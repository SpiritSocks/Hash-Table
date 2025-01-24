#include <iostream>
#include <list>
#include <string>

//Hashtable to implement [905, Jimmy]

class HashTable {
private:
    static const int hashGroups = 10;
    std::list<std::pair<int,std::string>> table[hashGroups]; // Hash table of size N -> [ [key0, value0], [key1, value1],..., [key(N-1), value(N-1)] ]
public:
    [[nodiscard]] bool isEmpty() const;
    [[nodiscard]] static int hashFunction(int key) ;
    void insert(int key, std::string value);
    void removeItem(int key);
    void printTable();
};

bool HashTable::isEmpty() const {
    for (int i{}; i<hashGroups; i++) {
        if (!table[i].empty()) {
            return false;
        }
    }
    return true;
}

int HashTable::hashFunction(int key) {
    return key%hashGroups; //Key: 905, in return -> 5
}

void HashTable::insert(int key, std::string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            std::cout <<"[WARNING] Key exists. Value replaced"<<std::endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }
}


void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            std::cout <<"[INFO] Item removed"<<std::endl;
            break;
        }
    }
    if (!keyExists) {
        std::cout <<"[WARNING] Key does not exist"<<std::endl;
    }
}

void HashTable::printTable() {
    for (int i{}; i<hashGroups; i++) {
        if (table[i].empty()) {
            continue;;
        }
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            std::cout << bItr->first << " " << bItr->second << std::endl;
        }
    }
}

int main() {

    HashTable HT;
    if (HT.isEmpty()) {
        std::cout << "[ERROR] HashTable is empty."<<std::endl;
    }else {
        std::cout << "[ISSUE] Not working"<<std::endl;
    }

    HT.insert(905,"Jimmy");
    HT.insert(193,"Chimmy");
    HT.insert(111,"Bimmy");
    HT.insert(164,"Rimmy");
    HT.insert(199,"Zimmy");
    HT.insert(187,"Qimmy");
    HT.insert(187,"Yimmy");

    HT.printTable();

    HT.removeItem(193);
    HT.removeItem(000);

    if (HT.isEmpty()) {
        std::cout << "[ISSUE] Not working"<<std::endl;
    }else {
        std::cout << "[NOTE] Good job."<<std::endl;
    }


    return 0;
}