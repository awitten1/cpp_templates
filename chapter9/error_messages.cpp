
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>


int main() {
    std::map<std::string, double> coll = {{"string1", 4.3}, {"string2", 5.21}, {"string3", 5.2}};

    auto foundString = coll.find("string1") != coll.end();
    std::cout << std::boolalpha << foundString << std::endl;

    auto pos = std::find_if(coll.begin(), coll.end(), [](auto&& s) { return s.first == "string2"; });
    return 0;
}

