#include <iostream>
#include <string>
using namespace std;

/*
Static Polymorphism (Compile-time polymorphism) in real life says that
the same action can behave differently depending on the input parameters.
For example, a Manual car can accelerate by a fixed amount or by a
specific amount you request. In programming, we achieve this via method
overloading: multiple methods with the same name but different signatures.
*/

class ManualCar {

protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    // CONSTRUCTOR
    ManualCar(string b, string m){
        this -> brand = b;
        this -> model = m;
        this -> isEngineOn = false;
        this -> currentGear = 0;
        this -> currentSpeed = 0;
    }

    // METHODS FOR MANUAL CAR
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    // OVER-LOADING -> STATIC POLYMORPHISM
    void acceleration(){
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void acceleration(int speed){
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += speed;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0){
            currentSpeed = 0;
        }
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }
};

// MAIN METHOD

int main() {
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->acceleration();
    myManualCar->acceleration(40);
    myManualCar->brake();
    myManualCar->stopEngine();

    // Cleanup
    delete myManualCar;

    return 0;
}