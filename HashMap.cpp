#include <iostream>
#include <string>
#include <sstream>
#include <functional>

#include "HashMap.hpp"

struct Hash
{

    unsigned int DefaultHashFunction(const std::string& key)
    {

        unsigned int index = 0;

        for(unsigned int i = 0; i < key.length(); i++) {
            index += key[i];
        }

        return index;

    }

};

HashMap::HashMap():
bc(INITIAL_BUCKET_COUNT), sz(0)
{

    Hash h;
    SomeHashFunction = std::bind(&Hash::DefaultHashFunction, &h, std::placeholders::_1);

    HashTable = new Node*[INITIAL_BUCKET_COUNT];

    for(int i = 0; i < INITIAL_BUCKET_COUNT; i++) {
        HashTable[i] = nullptr;
    }

}

HashMap::~HashMap()
{

}

void HashMap::put(const std::string& key, const std::string& value)
{

    // break out of the function if the key already exists
    if(containsKey(key))
    {
        return;
    }

    // initialize
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    // create a new key-value pairing
    Node* n = new Node;
    n->key = key;
    n->value = value;
    n->next = nullptr;

    Node* temp = HashTable[i];

    // pass the reference of the new key-value pairing to the root if it is null
    if(temp == nullptr)
    {
        HashTable[i] = n;
        sz++;
        return;
    }

    // traverse through the linked list and have "temp" refer to the head Node
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = n;
    sz++;

}

void HashMap::remove(const std::string& key)
{

    // initialize
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    Node* temp = HashTable[i];

    if(temp == nullptr)
    {
        return;
    }

    if(temp->key == key)
    {
        HashTable[i] = temp->next;
        temp->next = nullptr;
        delete temp;
        sz--;
        return;
    }

    Node* curr = temp->next;

    while(curr != nullptr)
    {
        if(curr->key == key)
        {
            temp->next = curr->next;
            curr->next = nullptr;
            delete curr;
            sz--;
            return;
        }

        temp = curr;
        curr = curr->next;
    }

}

bool HashMap::containsKey(const std::string& key) const
{

    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    Node* temp = HashTable[i];

    while(temp != nullptr)
    {
        if(temp->key == key)
        {
            return true;
        }
        temp = temp-> next;
    }

    return false;

}

void HashMap::reHash()
{

}

double HashMap::loadFactor() const
{
    return (double)sz / (double)bc;
}

void HashMap::tableCopy(Node *Target[], Node *Source[], unsigned int cap)
{

}

HashMap::HashMap(const HashMap& hm)
{

}

std::string HashMap::get(const std::string& key) const
{

    // initialize
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    std::string val = "";

    Node* temp = HashTable[i];

    while(temp != nullptr)
    {
        if(temp->key == key)
        {
            val = temp->value;
        }

        temp = temp->next;
    }

    return val;

}

void HashMap::ClearTable()
{

}

unsigned int HashMap::maxBucketSize() const
{

    unsigned int max = 0;

    for(int i = 0; i < bc; i++)
    {
        Node* temp = HashTable[i];
        unsigned int count = 0;

        while(temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        if(count > max)
        {
            max = count;
        }
    }

    return max;

}

unsigned int HashMap::bucketCount() const
{
    return bc;
}

unsigned int HashMap::size() const
{
    return sz;
}

