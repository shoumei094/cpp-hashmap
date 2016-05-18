#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>

class HashMap
{
public:

typedef std::function<unsigned int(const std::string&)> HashFunction;


static const unsigned int INITIAL_BUCKET_COUNT = 10;

public:

HashMap();

HashMap(HashFunction hashFunction);

HashMap(const HashMap& hm);
~HashMap();
HashMap& operator=(const HashMap& hm);

void add(const std::string& key, const std::string& value);

void remove(const std::string& key);

bool contains(const std::string& key) const;

std::string value(const std::string& key) const;

unsigned int size() const;

unsigned int bucketCount() const;

double loadFactor() const;

unsigned int maxBucketSize() const;

void ClearTable();

private:

struct Node
{
std::string key;
std::string value;
Node* next;
};

void tableCopy(Node *Target[], Node *Source[], unsigned int cap);
HashFunction SomeHashFunction;

Node **HashTable;

unsigned int bc;
unsigned int sz;

void reHash();

};

#endif // HASHMAP_HPP
