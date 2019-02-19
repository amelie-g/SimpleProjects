#include <iostream>
#include <cmath>
using namespace std;


void get_input(double &side_a, double &side_b, double &side_c)
{
  cout << "Input the lengths of three sides of a triangle " << endl;
  cout << "Enter a positive nonzero number for the length of side a:";
  cin >> side_a;
  cout << "Enter a positive nonzero number for the length of side b:";
  cin >> side_b;
  cout << "Enter a positive nonzero number for the length of side c:";
  cin >> side_c;
}

bool is_triangle(double side_a, double side_b, double side_c)
{
  if (side_a + side_b >= side_c)
    return true;
  else
    return false;
}

double semiperimeter(double side_a, double side_b, double side_c)
{
  double s = (side_a + side_b + side_c) / 2;
  return s;
}

void triangle_area(double side_a, double side_b, double side_c, double &perimeter, double &area) {
  
  if(!is_triangle(side_a, side_b, side_c)){
    cout << "The given lengths of the sides do not make a triangle." << endl;
    
  }
  
  double s = semiperimeter(side_a, side_b, side_c);
  area = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
  perimeter = side_a + side_b + side_c;

}

int main(){					
  double a;
  double b;
  double c;
  get_input(a, b, c);
  double perimeter, area;
  triangle_area(a, b, c, perimeter, area);
  cout <<"The perimeter is: ";
  cout << perimeter;
  cout << " The area is: ";
  cout << area << endl;
}

