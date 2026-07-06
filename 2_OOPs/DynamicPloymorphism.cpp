#include <iostream>
#include <string>
using namespace std;

/*
Dynamic Polymorphism in real life says that 2 Objects coming from same
family will respond to same stimulus differently. Like in real world Manual
car and Electric car will respond to accelerate() differently.

To represent this in programming, we create a parent class that defines all
characters and behaviours that are generic to all child classes and are also same in
all child classes but make those methods abstract(virtual) that are generic to all
child classes but all child class will behave differently. Then those child class
will provide implementation details of these abstract methods the way they want.
*/

class Car {

protected:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;

public:
    Car(string b, string m){
        this -> brand = b;
        this -> model = m;
        currentSpeed = 0;
        isEngineOn = false;
    }

    // COMMON METHODS FOR ALL CAR
    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    virtual void acceleration() = 0; // ABSTRACT METHOD FOR DYNAMIC POLYMORPHISM
    virtual void brake() = 0; // ABSTRACT METHOD FOR DYNAMIC POLYMORPHISM
    virtual ~Car() {};  // VIRTUAL DISTRUCTOR
};

// CHILD CLASS
class ManualCar : public Car {

private:
    int currentGear;

public:
    ManualCar(string b, string m) : Car(b, m){
        currentGear = 0;
    }

    // SPECIAL METHOD FOR MANUAL CAR
    void shiftGear(int gear){
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    // OVER-RIDING ACCELERATION -> DYNAMIC POLYMORPHISM
    void acceleration(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currentSpeed += 50;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    // OVER-RIDING BREKE -> DUNAMIC POLYMORPHISM
    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0){
            currentSpeed = 0;
        } 
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }
};

class ElectricCar : public Car {

private:
    int batteryLevel;

public:
    ElectricCar(string b, string m) : Car(b, m){
        this -> batteryLevel = 100;
    }

    // SPECIAL METHOD FOR ELECTRIC CAR
    void chargeBattery() {
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }

    // OVER-RIDING ACCELERATION
    void acceleration(){
        if(!isEngineOn){
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }

        if(batteryLevel <= 0){
            cout << brand << " " << model << " : Battery dead! Cannot accelerate." << endl;
            return;
        }

        batteryLevel -= 5;
        currentSpeed += 25;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }

    // OVER-RIDING BRAKE - DYNAMIC POLYMORPHISM
    void brake() {
        currentSpeed -= 15;
        if (currentSpeed < 0){
            currentSpeed = 0;
        } 
        cout << brand << " " << model << " : Regenerative braking! Speed is now " << currentSpeed << " km/h. Battery at " << batteryLevel << "%." << endl;
    }
};
int main(){
        Car* myManualCar = new ManualCar("Ford", "Mustang");
    myManualCar -> startEngine();
    myManualCar -> acceleration();
    myManualCar -> acceleration();
    myManualCar -> brake();
    myManualCar -> stopEngine();

    cout << "----------------------" << endl;

    Car* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar -> startEngine();
    myElectricCar ->  acceleration() ;
    myElectricCar -> acceleration();
    myElectricCar -> brake();
    myElectricCar -> stopEngine();

    // Cleanup
    delete myManualCar;
    delete myElectricCar;

    return 0;
    
    return 0;
}