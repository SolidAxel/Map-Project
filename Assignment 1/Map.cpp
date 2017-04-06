//
//  Map.cpp
//  Assignment 1
//
//  Created by Axel Garcia on 2/13/17.
//  Copyright © 2017 Axel Garcia. All rights reserved.
//

#include "Map.h"
#include <iostream>


Map::Map(){
    head = nullptr;
}

Map::~Map(){
    Node* p = new Node;
    while (head != nullptr)  {
        p = head;
        head = head->next;
        delete p;
    }
}
Map::Map(const Map &other){
    if (other.empty() ) {
        head = nullptr;
    } else {
        head = new Node;
        head -> name = other.head->name;
        head-> number = other.head->number;
        Node* q = head;
        Node* p = other.head->next;
        while ( p != nullptr ) {
            q->next = new Node;
            q->next->name = p ->name;
            q->next->number = p ->number;
            p=p->next;
            q=q->next;
        }
    }
}
Map& Map::operator=(const Map& map) {
    if (this != &map) {
        Node* p = new Node();
        while (head != nullptr)  {
            p = head;
            head = head->next;
            delete p;
        }
        if (map.empty()) {
            head = nullptr;
        }
        else {
            head = new Node;
            head ->name = map.head ->name;
            head ->number = map.head ->number;
            Node* q = head;
            Node* p = map.head->next;
            while ( p != nullptr ) {
                q->next = new Node;
                q->next->name = p->name;
                q->next->number = p->number;
                p=p->next;
                q=q->next;
            }
        }
    }
    return *this;
}
bool Map::empty() const{
    if(head == nullptr){
        return true;
    }
    else
        return false;
}
int Map::size() const{
    int counter = 0;
    Node*ptr = head;
    while (ptr!=nullptr) {
         counter++;
        ptr=ptr->next;
    }
    return counter;
}
bool Map::insert(const KeyType& key, const ValueType& value){
    bool flag = false;
    
    Node* ptr = new Node();
    ptr -> number = value;
    ptr -> name  = key;
    ptr -> next = head;
    if (head == nullptr) {
        head = ptr;
        flag = true;
    }
    else{
       
            if (contains(key)) {
                flag = false;
            }
            else{
                head = ptr;
                flag = true;
            }
        
    }
    return flag;
}
bool Map::update(const KeyType &key, const ValueType &value){
    Node* copy = head;
    while (copy -> next != nullptr && copy->name != key) {
        copy = copy->next;
    }
    if (copy -> name == key) {
        copy -> number = value;
        return true;
    }
    else
        return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value){
    Node* copy = head;
    Node* data = new Node;
    data->name = key;
    data->number = value;
    
    while (copy -> next != nullptr && copy->name != key) {
        copy = copy->next;
    }
    if (copy -> name == key) {
        copy -> number = value;
        return true;
    }
    else if(copy -> name != key){
        copy -> next = data;
        return true;
    }
    else
        return false;
}
bool Map::erase(const KeyType& key){
    bool flag = false;
    Node *ptr1;
    Node *toBeDeleted;
    
    if (head->name == key) {
        toBeDeleted = head;
        head = toBeDeleted->next;
        delete toBeDeleted;
        flag = true;
    }
    
    ptr1 = head;
    toBeDeleted = head->next;
    
    while (toBeDeleted != nullptr) {
        if (toBeDeleted->name == key) {
            ptr1->next = toBeDeleted->next;
            delete toBeDeleted;
            flag = true;
            break;
        }
        ptr1 = toBeDeleted;
        toBeDeleted = toBeDeleted->next;
    }
    return flag;
}
bool Map::contains(const KeyType& key)const{
    bool flag = false;
    if (head == nullptr) {
        return false;
    }
    else{
    for (Node*ptr = head; ptr!=nullptr; ptr = ptr->next) {
        if (ptr->name == key) {
            flag = true;
        }
        else
            return flag;
    }
    if (flag == true) {
        return true;
    }
    else
        return false;
    }
}
bool Map::get(const KeyType& key, ValueType& value) const{
    bool flag = false;
    for (Node*ptr = head; ptr!=nullptr; ptr = ptr->next) {
        if (ptr->name == key) {
            flag = true;
            value = ptr->number;
        }
    }
    if (flag == true) {
        return true;
    }
    else
        return false;
}
bool Map::get(int i, KeyType& key, ValueType& value) const{
    if (i<size() && i>=0) {
        Node*ptr = head;
        for (int start = 0; start < i; start++) {
            ptr=ptr->next;
        }
        key = ptr->name;
        value = ptr->number;
        return true;
    }
    else
        return false;
}
void Map::swap(Map &other){
        Node* ptr = other.head;
        Node* thisPtr = this->head;
        
        other.head = thisPtr;
        this->head = ptr;
}

bool combine(const Map& m1, const Map& m2, Map& result){
    bool flag = true;
    KeyType key;
    ValueType v1, v2;
    Map temp;
    
    if (!result.empty()) {
        if ((&m1 == &m2) && (&m1 == &result)) {
            return flag;
        }
        else if ((&m1 == &m2) && (&m1 != &result)){
            result = m1;
            return flag;
        }
        else{
            for(int i = 0; i< m1.size(); i++){
                if (m1.get(i, key, v1) == m2.get(key,v2)) {
                    if(v1 == v2)
                        result.insert(key, v1);
                    else
                        flag = false;
                }
                else if(!m2.contains(key))
                    temp.insertOrUpdate(key, v1);
            }
            for(int i = 0; i< m1.size(); i++){
                m2.get(i,key,v2);
                if(!m1.contains(key))
                    temp.insert(key, v2);
            }
            result = temp;
            return flag;
            
        }
    }
    else{
        for (int i = 0; i < m1.size(); i++) {
            if(m1.get(i,key, v1) == m2.get(key, v2)){
                if(v1 == v2)
                    result.insert(key, v1);
                else
                    flag = false;
            }
            else if (!m2.contains(key))
                result.insert(key, v1);
        }
        for (int i = 0; i < m2.size(); i++) {
            m2.get(i, key, v2);
            if (!m1.contains(key)) {
                result.insert(key, v2);
            }
        }
        return flag;
    }
}
void subtract(const Map& m1, const Map& m2, Map& result){
    KeyType key;
    ValueType v1;
    if(result.empty()){
        for(int i = 0; i < m1.size(); i++){
            m1.get(i, key, v1);
            if (!m2.contains(key)) {
                result.insert(key, v1);
            }
        }
    }
    else{
        Map temp;
        for(int i = 0; i < m1.size(); i++){
            m1.get(i, key, v1);
            if (!m2.contains(key)) {
                temp.insert(key, v1);
            }
        }
        result = temp;
    }
}





