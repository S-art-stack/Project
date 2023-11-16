package com.mycompany.energymanagementsystem;

public class Control {

    // turn light on off
    public void light(String s) {
        if (s.equals("ON")) {
            Status.Light = true;
        } else {
            Status.Light = false;
        }
    }

    // day on off
    public void day(String d) {
        if (d.equals("YES")) {
            Status.Day = true;
            Status.Shading = false;
            Status.Light = false;
        }
        else {
            Status.Day = false;
            Status.Shading = true;
            if (Status.PersonPresent > 0) {
                Status.Light = true;
            }
        }
    }


    // turn shading on off
    public void shading(String s) {
        if (s.equals("ON")) {
            Status.Shading = true;
        } else {
            Status.Shading = false;
        }
    }

    // turn ac on off
    public void ac(double t) {
        Status.AC = t;
        Status.Heater = 0.0;
    }

    // turn ac on off
    public void heater(double t) {
        Status.Heater = t;
        Status.AC = 0.0;
    }

    // update temperature
    public void temperature(double t) {
        Status.Heater = 0.0;
        Status.Temperature = t;
        Status.AC = t;
    }

    // update person
    public void person(int p) {
        Status.PersonPresent = p;
        if (Status.PersonPresent == 0) {
            Status.AC = 0.0;
            Status.Heater = 0.0;
        }
        else {
            if (Status.Day == false) {
                Status.Light = true;
            }
        }
    }
}
