#ifndef ELEMENT_H
#define ELEMENT_H

#include <utility>
#include <string>
#include <map>

class Element
{
private:
    std::map<std::string, std::pair<bool, short>> elements_map;

public:
    // get data
    Element()
    {
        // turnoff = default value
        turnoff();
    }
    std::pair<bool, short> get(std::string ele)
    {
        return elements_map[ele];
    }

    // set data
    void set(std::string ele, std::pair<bool, short> state)
    {
        elements_map[ele] = state;
    }

    // get all the data map
    std::map<std::string, std::pair<bool, short>> getall()
    {
        return elements_map;
    }

    // reset the system and set all the value to default
    void turnoff()
    {
        // store all the element(key) & their status(value)
        std::pair<bool, short> base_pair = {false, -1};
        elements_map["Light"] = base_pair;
        elements_map["Shading"] = base_pair;
        elements_map["Fan"] = base_pair;
        elements_map["AC"] = base_pair;
        elements_map["Heater"] = base_pair;
        elements_map["Temperature"] = base_pair;
        elements_map["People"] = base_pair;
    }
};

#endif // ELEMENT_H