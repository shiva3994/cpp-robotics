//////////////////////////////////////////////////////////////////////////////////////////

// int age = 25;          // whole numbers
// double price = 9.99;   // decimals
// char grade = 'A';      // single character
// bool isReady = true;   // true/false
// string name = "Shiva"; // text (needs #include <string>)

//////////////////////////////////////////////////////////////////////////////////////////

// Declare an int variable called battery_level and set it to 85 - Print "Battery level: 85%" using std::cout

// #include <iostream>
// int main() {
//     int battery_level = 85;
//     std::cout << "Battery level: " << battery_level << "%" << std::endl;
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////////

// Declares a double variable celsius set to 25.0
// Calculates Fahrenheit using the formula: fahrenheit = (celsius * 9/5) + 32
// Prints something like "25 Celsius is 77 Fahrenheit"

#include <iostream>

int main()
{
    double celcius = 25.0;
    double fahrenheit = (celcius * 9 / 5) + 32;
    std::cout << celcius << " Celcius is " << fahrenheit << " Fahrenheit " << std::endl;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

/*

#include <iostream>  // Imports tools needed to print text on the screen.
int main() {         // Starts the main container where the program begins running.
    double celcius = 25.0;  // Creates a decimal variable and sets Celsius to 25.0.
    double fahrenheit = (celcius * 9/5) + 32;  // Calculates and stores the conversion to Fahrenheit.
    std::cout << celcius << " Celcius is " << fahrenheit << " Fahrenheit " << std::endl;  // Prints the conversion result and a new line.
    return 0;        // Signals to the operating system that the program ran successfully.
}                    // Marks the official end of the entire C++ program.

*/

//////////////////////////////////////////////////////////////////////////////////////////

// To execute // g++ 1Variable.cpp -o 1Variable.exe; .\1Variable.exe