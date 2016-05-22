#include <iostream>
#include <string>
#include <sstream>

#include "HashMap.hpp"

using namespace std;


int main()
{
    HashMap hashMap;
    hashMap.put("a", "shoumei");
    hashMap.put("a", "gengar");
    hashMap.put("a", "caterpie");
    hashMap.put("a", "asdf");
    hashMap.put("e", "qwerty");
    hashMap.put("f", "123");
    hashMap.put("g", "456");
    hashMap.put("h", "789");
    hashMap.put("i", "0000000");
    hashMap.put("j", "xxxxxxx");
    hashMap.put("k", "california");
    hashMap.put("l", "love");
    hashMap.put("m", "art");
    hashMap.put("n", "of");
    hashMap.put("o", "life");
    hashMap.put("p", "!!!");
    hashMap.remove("p");
    hashMap.remove("a");
    hashMap.remove("x");
    hashMap.remove("z");

    string g = hashMap.get("e");

    unsigned int a = hashMap.size();

    unsigned int m = hashMap.maxBucketSize();

    cout << a << endl;
    cout << g << endl;
    cout << m << endl;

    return 0;
}
