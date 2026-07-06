#include <iostream>
#include <string>
using namespace std;

/*
Encapsulation says 2 things:
1. An Object's Characteristics and its behaviour are encapsulated together
within that Object.
2. All the characteristics or behaviours are not for everyone to access.
Object should provide data security.

We follow above 2 pointers about Object of real world in programming by:
1. Creating a class that act as a blueprint for Object creation. Class contain
all the characteristics (class variable) and behaviour (class methods) in one block,
encapsulating it together.
2. We introduce access modifiers (public, private, protected) etc to provide data
security to the class members.
*/

class SportsCar {

    // INITIALLISATION
    private:
        string brand;
        string model;
        bool isEnginOn;
        int currentSpeed;
        int currentGear;
        string tyreCompany;

    // CONSTRUCTOR
    public:
    SportsCar(string b, string m){
        this -> brand = b;
        this -> model = m;
        isEnginOn = false;
        currentSpeed = 0;
        currentGear = 0;
        tyreCompany = "MRF";
    }

    // METHODS 

    // GETTER AND SETTER
    int getSpeed(){
        return this -> currentSpeed;
    }

    string getTyreCompany(){
        return  this -> tyreCompany;
    }

    void setTyreCompany(string tyreCompany){
        this -> tyreCompany = tyreCompany;
    }

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

    ~SportsCar() {}
};

// MAIN 
int main(){

    SportsCar* myCar = new SportsCar("Ford", "Mustang");

    myCar -> startEngin();
    myCar -> shiftGrear(1);
    myCar -> acceleration();
    myCar -> shiftGrear(2);
    myCar -> setTyreCompany("CEAT");
    myCar -> acceleration();
    myCar -> brake();
    myCar -> stopEngin();

    // Setting arbitrary value to speed.
    // mySportsCar->currentSpeed = 500;
    // cout << "Current Speed of My Sports Car is set to " << myCar -> currentSpeed << endl;
    cout << "My car uses a tyre of -> " << myCar -> getTyreCompany() << endl;
    cout << "Current Speed of My Sports Car is " << myCar -> getSpeed() << endl;


    // FREE THE MEMORY
    delete myCar;

    return 0;
}