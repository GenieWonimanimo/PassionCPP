#include <iostream>
using namespace std;

class Car
{
private:
    int fuelGauge;
public:
    Car(int fuel) : fuelGauge(fuel)
    { }
    void ShowCarState() {cout << "remain fuel: " << fuelGauge << endl;}
};

class Truck : public Car
{
private:
    int freightWeight;
public:
    Truck(int fuel, int weight)
        : Car(fuel), freightWeight(weight)
    { }
    void ShowTruckState()
    {
        ShowCarState();
        cout << "freight weight: " << freightWeight << endl;
    }
};

int main(void)
{
    Car* pcar1 = new Truck(80, 200);
    //Truck* ptruck1 = dynamic_cast<Truck*>(pcar1); // cast from base to dervied, compile error! -> we need static_cast

    Car* pcar2 = new Car(120);
    //Truck* ptruck2 = dynamic_cast<Truck*>(pcar2); // cast from base to derived, compile error!

    Truck* ptruck3 = new Truck(70, 150);
    Car* pcar3 = dynamic_cast<Car*>(ptruck3); // compile OK
    pcar3->ShowCarState();
    return 0;
}