#include <iostream>
#include <cmath>
using namespace std;

int main() {

const double GRAVITY = 0.00000006673;
double mass1, mass2, dist;
double gravforce;


cout << "Enter the mass of the first object(in kg): ";
cin >> mass1;

cout << "Enter the mass of the second object(in kg): ";
cin >> mass2;
 
cout << "Enter the distance between the objects(in meters): ";
cin >> dist;

gravforce = ((GRAVITY * mass1 * mass2) / (dist * dist));


cout << "Results: " << endl;
cout << "The mass of the first object is: " << mass1 << "kg" << endl;
cout << "The mass of the second object is: " << mass2 << "kg" << endl;
cout << "The distance between the two objects is: " << dist <<" meters"<< endl;
cout << "The gravitational constant is: " << GRAVITY << " cm^3/(g * sec^2)" <<endl;
cout << "The gravitational force between the two objects is: " << gravforce <<endl;

 return 0;
 
}
