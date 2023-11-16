package com.mycompany.energymanagementsystem;

import java.util.Scanner;


// Main class to demonstrate the project
public class SmartBuildingEMS {

    // print
    public static void print(String s) {
        System.out.print(s);
    }

    public static void println(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {
        // Instantiate and use the classes to demonstrate functionality
        // input object
        Scanner input1 = new Scanner(System.in);

        // sensor object
        // control objext
        Control control = new Control();

        System.out.println("--------------Smart Building Energy Mangement System--------------");
        System.out.println("Please Enter some basic information to start the system");

        // input section temperature
        double tempTemp;
        while (true) {
            System.out.print("Temperature: ");
            tempTemp = input1.nextDouble();
            if (tempTemp < 15.0 || tempTemp > 35.0) {
                System.out.println("Please enter a valid temperature between 15.0 - 35.0");
            } else {
                break;
            }
        }

        // input section day
        String tempDay;
        while (true) {
            System.out.print("Day (Enter YES / NO): ");
            tempDay = input1.next().toUpperCase();
            if (tempDay.equals("YES") || tempDay.equals("NO")) {
                break;
            } else {
                System.out.println("Please enter a valid Input as day (YES / NO)");
            }
        }

        // input section person
        int tempPer;
        while (true) {
            System.out.print("Number of person in a room : ");
            tempPer = input1.nextInt();
            if (tempPer < 0) {
                System.out.println("Please enter a valid number. Person can not be negative.");
            } else {
                break;
            }
        }

        // updating status
        Status.Temperature = tempTemp;
        if (Status.Temperature >= 24) {
            Status.AC = 23.0;
            Status.Heater = 0.0;
        } else {
            Status.AC = 0.0;
            Status.Heater = 23.0;
        }
        if (tempDay.equals("YES")) {
            Status.Day = true;
            Status.Light = false;
            Status.Shading = false;
        }
        else  {
            Status.Day = false;
            Status.Light = true;
            Status.Shading = true;
        }
       

        Status.PersonPresent = tempPer;

        // process
        System.out.println("Choose Number of Operations:");
        while (true) {
            // light
            System.out.print("1. Light ");
            if (Status.Light == false || Status.PersonPresent == 0) {
                println("OFF");
            } else {
                println("ON");
            }

            // shading
            print("2. Shading ");
            if (Status.Shading == false) {
                println("OFF");
            } else {
                println("ON");
            }

            // ac
            print("3. AC ");
            if (Status.AC != 0.0 && Status.PersonPresent > 0) {
                print("ON ");
                System.out.println(Status.AC);
            } else {
                println("OFF");
            }

            // heater
            print("4. Heater ");
            if (Status.Heater != 0.0 && Status.PersonPresent > 0) {
                print("ON ");
                System.out.println(Status.Heater);
            } else {
                println("OFF");
            }

            // temperature
            println("5. Update Temperature (Current Temperature: " + Double.toString(Status.Temperature) + ")");

            // day
            print("6. Update Day (Current Status: ");
            if (Status.Day == true) {
                println("Sun rised)");
            } else {
                println("Sunset)");
            }

            // person
            println("7. Update Number of Person (Current Person: " + Status.PersonPresent + ")");

            // solar
            println("8. Manage Renewable Energy Source (Solar)");

            println("");
            print("Operation Number(1-8): ");
            int operation = input1.nextInt();

            if (operation == 1) {
                // light
                String lightInput;
                while (true) {
                    print("Do you want to turn ON or OFF the light: ");
                    lightInput = input1.next().toUpperCase();
                    if (lightInput.equals("ON") || lightInput.equals("OFF")) {
                        break;
                    } else {
                        println("Please Select ON or OFF!");
                    }
                }
                // checking if person present is 0 or not. we cant turn on light if person
                // present is 0
                if (Status.PersonPresent == 0) {
                    println("Can not turn the light as there is no person in the room.\nPlease Update the person field to turn on the light.");
                } else {
                    control.light(lightInput);
                }
            } else if (operation == 2) {
                // shading
                String ShadeInput;
                while (true) {
                    print("Do you want to turn ON or OFF the Shading: ");
                    ShadeInput = input1.next().toUpperCase();
                    if (ShadeInput.equals("ON") || ShadeInput.equals("OFF")) {
                        break;
                    } else {
                        println("Please Select ON or OFF!");
                    }
                }
                control.shading(ShadeInput);
            } else if (operation == 3) {
                // ac
                double ACInput;
                while (true) {
                    print("New AC Temperature: ");
                    ACInput = input1.nextDouble();
                    if (ACInput > 35 || ACInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                }
                control.ac(ACInput);
            } else if (operation == 4) {
                // heater
                double HeaterInput;
                while (true) {
                    print("New Heater Temperature: ");
                    HeaterInput = input1.nextDouble();
                    if (HeaterInput > 35 || HeaterInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                }
                control.heater(HeaterInput);
            } else if (operation == 5) {
                // temp
                double TempInput;
                while (true) {
                    print("New Temperature: ");
                    TempInput = input1.nextDouble();
                    if (TempInput > 35 || TempInput < 15) {
                        println("Please Select valid temperature between 15 to 35");
                    } else {
                        break;
                    }
                }
                control.temperature(TempInput);
            } else if (operation == 6) {
                // day
                String DayInput;
                while (true) {
                    print("Day(YES / NO): ");
                    DayInput = input1.next().toUpperCase();
                    if (DayInput.equals("YES") || DayInput.equals("NO")) {
                        break;
                    } else {
                        println("Please enter YES or NO.");
                    }
                }
                control.day(DayInput);
            } else if (operation == 7) {
                // person
                int PersonInput;
                while (true) {
                    print("New Person Number: ");
                    PersonInput = input1.nextInt();
                    if (PersonInput < 0) {
                        println("Please Select person number(greater or equal to 0)");
                    } else {
                        break;
                    }
                }
                control.person(PersonInput);
            } else if (operation == 8) {
                // solar
                if (Status.Day == true) {
                    // day
                    print("* Solar Panel working.\n");
                    if (Status.Light == true) {
                        print("* Using solar power to powerup the light.");
                    }
                    println("* Battery Status(Charging): 93% charged");
                } else {
                    // night
                    print("* Battery in stand by mode\n");
                    if (Status.Light == true) {
                        println("* Using solar power to powerup the light.");
                    }
                }
            } else {
                println("Operation out of range. Please select among 1 to 7.");
            }
        }
    }
}
