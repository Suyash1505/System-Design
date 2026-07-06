#include <iostream>
#include <string>
using namespace std;

/* 
    ABSTRACTION CLASS : 

    1. Act as an interface for the outside wrold to operate the car.
    2. This abstract class tells 'WHAT' all it can do rather then 'HOW' it does that.
    3. Since this is an abstract class we cannot directly create Objects of this class. 
    4. We need to Inherit it first and then that child class will have the responsibility to 
        provide implementation details of all the abstract (virtual) methods in the class.
    5. In our real world example of Car, imagine you sitting in the car and able to operate
    the car (startEngine, accelerate, brake, turn) just by pressing or moving some
    pedals/buttons/ steer the wheel etc. You dont need to know how these things work, and
    also they are hidden under the hood.
    6. This Class 'Car' denotes that (pedals/buttons/steering wheel etc).
*/

class Car {
    
    // INITIALLISATION
    public:
    virtual void startEngin() = 0;
    virtual void shiftGrear(int gear) = 0;
    virtual void acceleration() = 0;
    virtual void brake() = 0;
    virtual void stopEngin() = 0;
    virtual ~Car() {}
};

/*
1. This is a Concrete class (A class that provide implementation details of an abstract class).
Now anyone can make an Object of 'SportsCar' and can assign it to 'Car' (Parent class) pointer 
(See main method for this)

2. In our real world example of Car, as you cannot have a real car by just having its body only
(all these buttons or steering wheel). You need to have the actual implementation of 'What' happens
when we press these buttons. 'SportsCar' class denotes that actual implementation. 

3. Therefore, to denote a real world car in programming we created 2 classes.
One to denote all the user-interface like pedals, buttons, steering wheels etc ('Car' class).And,
Another one to denote the actual car with all the implementations of these buttons (SportsCar' class).
 
*/

class SportsCar : public Car {

    // INITIALLISATION
    public:
        string brand;
        string model;
        bool isEnginOn;
        int currentSpeed;
        int currentGear;

    // CONSTRUCTOR
    SportsCar(string b, string m){
        this -> brand = b;
        this -> model = m;
        isEnginOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    // METHODS
    void startEngin() {
        isEnginOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGrear(int gear){
        if(!isEnginOn){
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void acceleration(){
        if(!isEnginOn){
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0){
            currentSpeed = 0;
        }
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngin(){
        isEnginOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }
};

// MAIN 
int main(){

    Car* myCar = new SportsCar("Ford", "Mustang");

    myCar -> startEngin();
    myCar -> shiftGrear(1);
    myCar -> acceleration();
    myCar -> shiftGrear(2);
    myCar -> acceleration();
    myCar -> brake();
    myCar -> stopEngin();

    // FREE THE MEMORY
    delete myCar;

    return 0;
}