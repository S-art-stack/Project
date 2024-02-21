#ifndef ELEMENT_H
#define ELEMENT_H

#include <utility>
#include <string>
#include <map>

class Element
{
private:
    std::pair<bool, short> Light = {false, -1}, Shading = {false, -1}, Fan = {false, -1}, AC = {false, -1}, Heater = {false, -1}, Temperature = {false, -1};

public:
    // get data
    std::pair<bool, short> get(std::string ele)
    {
        if (ele == "Light")
            return Light;
        else if (ele == "Shading")
            return Shading;
        else if (ele == "Fan")
            return Fan;
        else if (ele == "AC")
            return AC;
        else if (ele == "Heater")
            return Heater;
        else if (ele == "Temperature")
            return Temperature;
    }

    std::map<std::string, std::pair<bool, short>> getall()
    {
        // store all the element(key) & their status(value)
        std::map<std::string, std::pair<bool, short>> mp;
        mp["Light"] = Light;
        mp["Shading"] = Shading;
        mp["Fan"] = Fan;
        mp["AC"] = AC;
        mp["Heater"] = Heater;
        mp["Temperature"] = Temperature;
        return mp;
    }
};

#endif // ELEMENT_H