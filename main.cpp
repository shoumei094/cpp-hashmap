#include <iostream>
#include <string>
#include <sstream>

#include "HashMap.hpp"

using namespace std;


int main()
{
    HashMap hashMap;
    const std::string a = "Hi";
    hashMap.add("a", "Asdf");
    if(hashMap.contains("a"))
    {
        cout << "WHAT" << endl;
    }
    cout << a << endl;
    return 0;
}
