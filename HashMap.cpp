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

HashMap::HashMap(HashFunction hashFunction):
SomeHashFunction(hashFunction), bc(INITIAL_BUCKET_COUNT), sz(0)
{

    HashTable = new Node*[INITIAL_BUCKET_COUNT];



}

HashMap::~HashMap()
{

}

void HashMap::add(const std::string& key, const std::string& value)
{
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    if(HashTable[i] == nullptr)
    {
        HashTable[i] = new Node;
        HashTable[i]->key = key;
        HashTable[i]->value = value;
        HashTable[i]->next = nullptr;
    }
    else
    {
        Node* n = HashTable[i];

        while(n->next != nullptr)
        {
            if(n->key == key)
            {
                std::cout << "Oops";
                return;
            }
            n = n->next;
        }

        if(n->key == key)
        {
            std::cout << "Oops";
            return;
        }

        n->next = new Node;
        n->next->key = key;
        n->next->value = value;
        n->next->next = nullptr;

    }

}

void HashMap::remove(const std::string& key)
{
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    if(HashTable[i] != nullptr)
    {
        Node* n = HashTable[i];


    }

}

bool HashMap::contains(const std::string& key) const
{
    unsigned int hashValue = SomeHashFunction(key);
    unsigned int i = hashValue % HashMap::bucketCount();

    Node* n = HashTable[i];

    while(n->next != nullptr)
    {
        if(n->key == key)
        {
            return true;
        }
        n = n-> next;
    }

    return false;
}

void HashMap::reHash()
{

}

double HashMap::loadFactor() const
{
    return 0;
}

void HashMap::tableCopy(Node *Target[], Node *Source[], unsigned int cap)
{

}

HashMap::HashMap(const HashMap& hm)
{

}

std::string HashMap::value(const std::string& key) const
{
    return "Hi";
}

void HashMap::ClearTable()
{

}

unsigned int HashMap::maxBucketSize() const
{

}

unsigned int HashMap::bucketCount() const
{
    return bc;
}

unsigned int HashMap::size() const
{
    return sz;
}

