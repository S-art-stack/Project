#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>
#include "element.h"

// pre declaration
void gui_line_divider();
void handle_invalid_input();
void showstatus(Element element);

int main()
{
    std::cout << "----- Smart Building Energy Management System -----\n";
    bool program_close = false;
    Element element;
    while (true)
    {
        std::cout << "Status\n";
        showstatus(element);
        gui_line_divider(); // divider line
        short opt;
        while (true)
        {
            std::cout << "\nChoose an option\n\t1. Update\n\t0. Exit\n\t: ";
            std::cin >> opt;
            if (std::cin.fail() || (opt != 1 && opt != 0))
            {
                // handling wrong input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Wrong option. (1 or 0)!\n";
            }
            else if (opt == 0)
            {
                // shut down the system
                std::cout << "System is turned of!\n";
                program_close = true;
                break;
            }
            else
                break;
        }
        if (program_close)
            break;
        gui_line_divider(); // divider line
        // update section
        while (true)
        {
            std::cout << "Choose an option to update:\n";
            std::vector<std::string> v = {"Light ON/OFF", "Shading ON/OFF", "Fan ON/OFF", "Change Temperature", "Number of People in room: "};
            for (short i = 0; i < (short)v.size(); i++)
                std::cout << "\t" << i + 1 << ". " << v[i] << '\n';
            std::cout << ": ";
            std::cin >> opt;
            if (std::cin.fail())
            {
                // handling wrong input
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // show error message
                std::cout << "Wrong opt. Press (1-" << (short)v.size() << ")!\n";
            }
            else if (opt >= 1 && opt <= (short)v.size())
                break;
            else
                std::cout << "Wrong opt. Press (1-" << (short)v.size() << ")!\n";
        }
        gui_line_divider(); // divider line
        // update process
        // light
        if (opt == 1)
        {
            while (true)
            {
                std::cout << "Choose an option:\n\t1. Light ON\n\t2. Light OFF\n\t: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! Press 1/2\n";
                }
                else if (opt >= 1 && opt <= 2)
                {
                    // light on
                    if (opt == 1)
                    {
                        if (element.get("People").first == false)
                        {
                            std::cout << "Light ON failed. No people in the room.\n";
                        }
                        else if (element.get("Light").first == true)
                        {
                            std::cout << "Light already on.\n";
                        }
                        else
                        {
                            // turning on light
                            element.set("Light", {true, -1});
                            std::cout << "Light ON Successfully.\n";
                        }
                    }
                    // light off
                    else
                    {
                        if (element.get("Light").first == false)
                        {
                            std::cout << "Light already off.\n";
                        }
                        else
                        {
                            // truning off light
                            element.set("Light", {false, -1});
                            std::cout << "Light ON Successfully.\n";
                        }
                    }
                    break;
                }
                else
                {
                    std::cout << "Wrong option! Press 1/2\n";
                }
            }
        }
        // shading
        // shading up = true, shading down = false
        else if (opt == 2)
        {
            while (true)
            {
                std::cout << "Choose an option:\n\t1. Shading UP\n\t2. Shading DOWN\n\t: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! Press 1/2\n";
                }
                else if (opt >= 1 && opt <= 2)
                {
                    // Shading UP
                    if (opt == 1)
                    {
                        if (element.get("Shading").first == true)
                        {
                            std::cout << "Shading already UP.\n";
                        }
                        else if (element.get("People").first == false)
                        {
                            std::cout << "Shading UP failed. No people in the room.\n";
                        }
                        else
                        {
                            // turning on shading
                            element.set("Shading", {true, -1});
                            std::cout << "Shading UP Successfully.\n";
                        }
                    }
                    // shading down
                    else
                    {
                        if (element.get("Shading").first == false)
                        {
                            std::cout << "Shading already DOWN.\n";
                        }
                        else
                        {
                            // shading down
                            element.set("Shading", {false, -1});
                            std::cout << "Shading DOWN Successfully.\n";
                        }
                    }
                    break;
                }
                else
                {
                    std::cout << "Wrong option! Press 1/2\n";
                }
            }
        }
        // Fan
        else if (opt == 3)
        {
            while (true)
            {
                std::cout << "Choose an option:\n\t1. Fan ON\n\t2. Fan OFF\n\t: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! Press 1/2\n";
                }
                else if (opt >= 1 && opt <= 2)
                {
                    // Fan on
                    if (opt == 1)
                    {
                        if (element.get("Fan").first == true)
                        {
                            std::cout << "Fan already on.\n";
                        }
                        else if (element.get("People").first == false)
                        {
                            std::cout << "Fan ON failed. No people in the room.\n";
                        }
                        else
                        {
                            // turning on Fan
                            element.set("Fan", {true, -1});
                            std::cout << "Fan ON Successfully.\n";
                        }
                    }
                    // Fan off
                    else
                    {
                        if (element.get("Fan").first == false)
                        {
                            std::cout << "Fan already off.\n";
                        }
                        else
                        {
                            // truning off Fan
                            element.set("Fan", {false, -1});
                            std::cout << "Fan ON Successfully.\n";
                        }
                    }
                    break;
                }
                else
                {
                    std::cout << "Wrong option! Press 1/2\n";
                }
            }
        }
        // temperature
        else if (opt == 4)
        {
            while (true)
            {
                std::cout << "Set Room Temperature:\n\t[15`C - 35`C]: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! Temperature must be between 15 - 35\n";
                }
                else if (opt >= 15 && opt <= 35)
                {
                    // setting ac / heater
                    // if temperature is less then or equal to 25`C then it can be
                    // managed with AC
                    if (element.get("People").first == false)
                    {
                        std::cout << "Can not change room temperature. No people in the room.\n";
                    }
                    else if (opt <= 25)
                        element.set("AC", {true, opt});
                    else
                        element.set("Heater", {true, opt});
                    break;
                }
                else
                {
                    std::cout << "Wrong option! Temperature must be between 15 - 35\n";
                }
            }
        }
        // people
        else if (opt == 5)
        {
            while (true)
            {
                std::cout << "Number of People in the room:\n\t[0 - 5 People]: ";
                std::cin >> opt;
                if (std::cin.fail())
                {
                    handle_invalid_input();
                    std::cout << "Wrong option! A room can contain maximum 0 - 5 people in our system.\n";
                }
                else if (opt >= 0 && opt <= 5)
                {
                    // if people = 0, set all the other parameter = false
                    if (!opt)
                    {
                        // turn off all the system
                        element.turnoff();
                    }
                    else
                    {
                        element.set("People", {true, opt});
                        // when people will be updated, light will be turn on
                        // in future when night feature will be added we can handle will more
                        // like when in night people update light will be kept turn off if
                        // it is turn off manually
                        element.set("Light", {true, opt});
                        // AC will be turn of in normal temperature
                        element.set("AC", {true, 23});
                    }
                    break;
                }
            }
        }
    }
    gui_line_divider(); // divider line
    return 0;
}

// defination

void gui_line_divider()
{
    std::cout << "--------------------------------------------\n";
    std::cout << "--------------------------------------------\n";
}

void handle_invalid_input()
{
    // handling wrong input
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showstatus(Element element)
{
    std::map<std::string, std::pair<bool, short>> mp = element.getall();
    for (auto pr : mp)
    {
        std::cout << "\t* " << pr.first << ": ";
        if (pr.second.first)
        {
            std::cout << "ON\n";
        }
        else
            std::cout << "OFF\n";
    }
}