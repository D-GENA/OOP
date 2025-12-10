<<<<<<< HEAD

=======
/*Name:Kavian Blades
  Student ID:2401010734
  Instructor Name:Doron Williams
  Date:Dec 07,2025
  Question #:2 (2.1,2.2,2.3) All done
  */
>>>>>>> ab6604aedbfeb46058602b2ce7251a5e26a8add6
#include <iostream>
using std::string;
using std::cout;
=======
#include <iostream>
using std::string;
using std::cout;
using std::cin;



class Converter{
private:
float value; 


Converter(){
    float value = 1.0f;
}

Converter(float v) {
        if(v > 0.0f) {
            value = v;
        } else {
            cout << "value must be greater than 0.0 /n setting the default value to (1.0)" <<;
            value = 1.0f;
        }
    }

    void USDToJMD() {
        float result = value * 137.83f;
        cout << value << " USD is approximately " << result << " JMD" <<;
    }

    void MilesToKilo() {
        float result = value * 1.6093f;
        cout << value << " Miles is approximately " << result << " Kilometer" <<;
    }

    void FahToCel() {
        float result = (value - 32) * 5.0f / 9.0f;
        cout << value << " Fahrenheit is approximately " << result << " Celsius" <<;
    }

    void LbsToKilo() {
        float result = value / 2.205f;
        cout << value << " Pounds is approximately " << result << " Kilograms" <<;
    }

    void GalsToLitres() {
        float result = value * 3.785f;
        cout << value << " Gallons is approximately " << result << " Litres" <<;
    }


};

class Converter{
private:
float value; 

public:
Converter(){
    float value = 1.0f;
}

Converter(float v) {
        cout << "Enter the vlaue you want to convert :";
        cin >> v;

        if(v > 0.0f) {
            value = v;
        } else {
            cout << "value must be greater than 0.0..... \nSetting the default value to (1.0).....\n\n";
            value = 1.0f;
        }
    }

    void USDToJMD() {
        float result = value * 137.83f;
        cout << value << " USD is about " << result << " JMD\n";
    }

    void MilesToKilo() {
        float result = value * 1.6093f;
        cout << value << " Miles is about " << result << " Kilometer\n";
    }

    void FahToCel() {
        float result = (value - 32) * 5.0f / 9.0f;
        cout << value << " Fahrenheit is about " << result << " Celsius\n";
    }

    void LbsToKilo() {
        float result = value / 2.205f;
        cout << value << " Pounds is about " << result << " Kilograms\n";
    }

    void GalsToLitres() {
        float result = value * 3.785f;
        cout << value << " Gallons is about " << result << " Litres\n\n";
    }


};
int main(){

Converter(5); 
Converter con;

con.USDToJMD();
con.MilesToKilo();
con.FahToCel();
con.LbsToKilo();
con.GalsToLitres();

}