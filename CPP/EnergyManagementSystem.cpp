#include <iostream>
#include <limits>
#include <string>
using namespace std;

// Class to store current status
class Status {
public:
    static bool SolarPanel, BatteryStatus, Day, VoltageInRange, Light, Shading, ElectricalLine;
    static double Temperature, AC, Heater;
    static int PersonPresent;
};

// Class for controlling operations
class Control {
public:
    // Turn light on/off
    void light(string s) {
        if (s == "ON") {
            Status::Light = true;
        } else {
            Status::Light = false;
        }
    }

    // Day on/off
    void day(string d) {
        if (d == "YES") {
            Status::Day = true;
            Status::Shading = false;
            Status::Light = false;
        } else {
            Status::Day = false;
            Status::Shading = true;
            if (Status::PersonPresent > 0) {
                Status::Light = true;
            }
        }
    }

    // Turn shading on/off
    void shading(string s) {
        if (s == "ON") {
            Status::Shading = true;
        } else {
            Status::Shading = false;
        }
    }

    // Turn AC on/off
    void ac(double t) {
        Status::AC = t;
        Status::Heater = 0.0;
        Status::Temperature = t;
    }

    // Turn heater on/off
    void heater(double t) {
        Status::Heater = t;
        Status::AC = 0.0;
        Status::Temperature = t;
    }

    // Update temperature
    void temperature(double t) {
        Status::Heater = 0.0;
        Status::Temperature = t;
        Status::AC = t;
    }

    // Update person
    void person(int p) {
        Status::PersonPresent = p;
        if (Status::PersonPresent == 0) {
            Status::AC = 0.0;
            Status::Heater = 0.0;
        } else {
            if (Status::Day == false) {
                Status::Light = true;
            }
        }
    }
};

// Initialize static variables of Status class
bool Status::SolarPanel, Status::BatteryStatus, Status::Day = false, Status::VoltageInRange, Status::Light, Status::Shading, Status::ElectricalLine;
double Status::Temperature = 0.0, Status::AC = 0.0, Status::Heater = 0.0;
int Status::PersonPresent = 0;

// Function to print outputs
void print(string s) {
    cout << s;
}

void println(string s) {
    cout << s << endl;
}

int main() {
    // Instantiate the Control class
    Control control;

    cout << "--------------Smart Building Energy Management System--------------" << endl;
    cout << "Please Enter some basic information to start the system" << endl;

    // Input section: Temperature
    double tempTemp;
    while (true) {
        try {
            cout << "Temperature: ";
            cin >> tempTemp;
            if (tempTemp < 15.0 || tempTemp > 35.0) {
                cout << "Please enter a valid temperature between 15.0 - 35.0" << endl;
            } else {
                break;
            }
        } catch (...) {
            cout << "Invalid Input format!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input section: Day
    string tempDay;
    while (true) {
        try {
            cout << "Day (Enter YES / NO): ";
            cin >> tempDay;
            for (char &c : tempDay) {
                c = toupper(c);
            }
            if (tempDay == "YES" || tempDay == "NO") {
                break;
            } else {
                cout << "Please enter a valid input as day (YES / NO)" << endl;
            }
        } catch (...) {
            cout << "Invalid Input format!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Input section: Person
    int tempPer;
    while (true) {
        try {
            cout << "Number of person in a room: ";
            cin >> tempPer;
            if (tempPer < 0) {
                cout << "Please enter a valid number. Person cannot be negative." << endl;
            } else {
                break;
            }
        } catch (...) {
            cout << "Invalid Input format!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Updating status
    Status::Temperature = tempTemp;
    if (Status::Temperature >= 24) {
        Status::AC = 23.0;
        Status::Heater = 0.0;
    } else {
        Status::AC = 0.0;
        Status::Heater = 23.0;
    }
    if (tempDay == "YES") {
        Status::Day = true;
        Status::Light = false;
        Status::Shading = false;
    } else {
        Status::Day = false;
        Status::Light = true;
        Status::Shading = true;
    }
    Status::PersonPresent = tempPer;

    // Process
    cout << "Choose Number of Operations:" << endl;
    while (true) {
        // Light
        cout << "1. Light ";
        if (!Status::Light || Status::PersonPresent == 0) {
            println("OFF");
        } else {
            println("ON");
        }

        // Shading
        cout << "2. Shading ";
        if (!Status::Shading) {
            println("OFF");
        } else {
            println("ON");
        }

        // AC
        cout << "3. AC ";
        if (Status::AC != 0.0 && Status::PersonPresent > 0) {
            cout << "ON " << Status::AC << endl;
        } else {
            println("OFF");
        }

        // Heater
        cout << "4. Heater ";
        if (Status::Heater != 0.0 && Status::PersonPresent > 0) {
            cout << "ON " << Status::Heater << endl;
        } else {
            println("OFF");
        }

        // Temperature
        println("5. Update Temperature (Current Temperature: " + to_string(Status::Temperature) + ")");

        // Day
        cout << "6. Update Day (Current Status: ";
        if (Status::Day) {
            println("Sunrise)");
        } else {
            println("Sunset)");
        }

        // Person
        println("7. Update Number of Person (Current Person: " + to_string(Status::PersonPresent) + ")");

        // Solar
        println("8. Manage Renewable Energy Source (Solar)");

        println("");
        cout << "Operation Number(1-8): ";
        int operation;
        cin >> operation;

        if (operation == 1) {
            // Light
            string lightInput;
            while (true) {
                try {
                    cout << "Do you want to turn ON or OFF the light: ";
                    cin >> lightInput;
                    for (char &c : lightInput) {
                        c = toupper(c);
                    }
                    if (lightInput == "ON" || lightInput == "OFF") {
                        break;
                    } else {
                        println("Please Select ON or OFF!");
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            // Checking if person present is 0 or not. We can't turn on light if no person is present
            if (Status::PersonPresent == 0) {
                println("Cannot turn on the light as there is no person in the room.");
                println("Please update the person field to turn on the light.");
            } else {
                control.light(lightInput);
            }
        } else if (operation == 2) {
            // Shading
            string shadeInput;
            while (true) {
                try {
                    cout << "Do you want to turn ON or OFF the Shading: ";
                    cin >> shadeInput;
                    for (char &c : shadeInput) {
                        c = toupper(c);
                    }
                    if (shadeInput == "ON" || shadeInput == "OFF") {
                        break;
                    } else {
                        println("Please Select ON or OFF!");
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.shading(shadeInput);
        } else if (operation == 3) {
            // AC
            double acInput;
            while (true) {
                try {
                    cout << "New AC Temperature: ";
                    cin >> acInput;
                    if (acInput > 35 || acInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.ac(acInput);
        } else if (operation == 4) {
            // Heater
            double heaterInput;
            while (true) {
                try {
                    cout << "New Heater Temperature: ";
                    cin >> heaterInput;
                    if (heaterInput > 35 || heaterInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.heater(heaterInput);
        } else if (operation == 5) {
            // Temperature
            double tempInput;
            while (true) {
                try {
                    cout << "New Temperature: ";
                    cin >> tempInput;
                    if (tempInput > 35 || tempInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.temperature(tempInput);
        } else if (operation == 6) {
            // Day
            string dayInput;
            while (true) {
                try {
                    cout << "Day(YES / NO): ";
                    cin >> dayInput;
                    for (char &c : dayInput) {
                        c = toupper(c);
                    }
                    if (dayInput == "YES" || dayInput == "NO") {
                        break;
                    } else {
                        println("Please enter YES or NO.");
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.day(dayInput);
        } else if (operation == 7) {
            // Person
            int personInput;
            while (true) {
                try {
                    cout << "New Person Number: ";
                    cin >> personInput;
                    if (personInput < 0) {
                        println("Please Select person number(greater or equal to 0)");
                    } else {
                        break;
                    }
                } catch (...) {
                    cout << "Invalid Input format!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
            control.person(personInput);
        } else if (operation == 8) {
            // Solar
            if (Status::Day) {
                // Day
                println("* Solar Panel working.");
                if (Status::Light) {
                    println("* Using solar power to power up the light.");
                }
                println("* Battery Status(Charging): 93% charged");
            } else {
                // Night
                println("* Battery in stand by mode");
                if (Status::Light) {
                    println("* Using solar power to power up the light.");
                }
            }
        } else {
            println("Operation out of range. Please select among 1 to 7.");
        }
    }

    return 0;
}
