/*Name:Kavian Blades
  Student ID:2401010734
  Instructor Name:Doron Williams
  Date:Dec 07,2025
  Question #:1 (1.1,1.2,1.3,1.4,1.5,1.6) All done
  */

#include <iostream>
using std::string;
using std::cout;

class Rectangle{
private:
    float lenght;
    float height;

public:
//My default Constructor
    Rectangle(){
    lenght = 5.0;
    height = 5.0;
    }

    void setLenght(float l){
         if(l > 0){
            lenght = l;
    }
    else{
        cout << "Lenght should be greater than 0.0";
    }
    }

    void setHeight(float h){
        if(h > 0){
            height = h;
    }
    else{
        cout << "Height should be greater than 0.0";
    }
        }

        // Getter for length
    float getLength() {
        return lenght;
    }

    // Getter for height
    float getHeight() {
        return height;
    }

    float calculateArea(){
        float Area = (lenght * height);
        cout << "Area of the Rectangle is : "<< Area;
        return Area;
    }

    float calculatePerimeter(){
        float Perimter = 2 * (lenght + height);
        cout <<"\n Perimeter of Rectangle is : "<< Perimter;
        return Perimter;
    }
};
//inherit  rectangle class
class Triangle : public Rectangle {
public:
    // Override area operation for a triangle
    float calculateArea() {
        float Area = (getLength() * getHeight()) / 2.0;
        cout << "\n Area of Triangle is: " << Area;
        return Area;
    }
};

int main()
{
Rectangle rec;
rec.calculateArea();      
rec.calculatePerimeter();

Triangle tri;
tri.calculateArea(); 
}