//
//  Map.h
//  Assignment 1
//
//  Created by Axel Garcia on 2/13/17.
//  Copyright © 2017 Axel Garcia. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include <string>


typedef std::string KeyType;
typedef double ValueType;

class Node{
public:
    Node(){
        next = nullptr;
    }
    KeyType name;
    ValueType number;
    Node* next;
};

class Map{
private:
    Node* head;
public:
    Map();
    ~Map();
    Map& operator=(const Map&);
    Map(const Map &other);
    bool empty() const;
    int size() const;
    bool insert(const KeyType& key, const ValueType& value);
    bool update(const KeyType& key, const ValueType& value);
    bool insertOrUpdate(const KeyType& key, const ValueType& value);
    bool erase(const KeyType& key);
    bool contains(const KeyType& key) const;
    bool get(const KeyType& key, ValueType& value) const;
    bool get(int i, KeyType& key, ValueType& value) const;
    void swap(Map& other);
};

bool combine(const Map& m1, const Map& m2, Map& result);
void subtract(const Map& m1, const Map& m2, Map& result);


#endif /* Map_h */
