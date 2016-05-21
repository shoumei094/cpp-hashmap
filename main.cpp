#include <iostream>
#include <string>
#include <sstream>

#include "HashMap.hpp"

using namespace std;


int main()
{
    HashMap hashMap;
    hashMap.put("a", "shoumei");
    hashMap.put("a", "shoumei");
    hashMap.put("a", "shoumei");
    hashMap.put("a", "shoumei");
    hashMap.put("e", "shoumei");
    hashMap.put("f", "shoumei");
    hashMap.put("g", "shoumei");
    hashMap.put("h", "shoumei");
    hashMap.put("i", "shoumei");
    hashMap.put("j", "shoumei");
    hashMap.put("k", "shoumei");
    hashMap.put("l", "shoumei");
    hashMap.put("m", "shoumei");
    hashMap.put("n", "shoumei");
    hashMap.put("o", "shoumei");
    hashMap.put("p", "shoumei");
    hashMap.remove("p");
    hashMap.remove("a");
    hashMap.remove("x");
    hashMap.remove("z");

    unsigned int a = hashMap.size();

    cout << a << endl;
    return 0;
}
