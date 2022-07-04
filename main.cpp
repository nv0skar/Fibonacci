// Fibonacci sequence calculator
// Copyright (C) 2022 Oscar
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
// Uncomment the following line if you want to hardcode the 'maxFibonacci' value instead of the program asking at execution
// #define maxFibonacci -1

using namespace boost::multiprecision;
using boost::multiprecision::cpp_dec_float_100;
using namespace std;

int main() {
    cout << "Fibonacci sequence calculator\n";

    // ---- Comment from here if you want to use the 'maxFibonacci' macro ----
    // Define the max Fibonacci number to calculate
    int maxFibonacci = -1;
    // Ask for the max Fibonacci number to calculate
    cout << "\nMax Fibonacci number to calculate? (Input -1 for no limit) (If no limit is set, the Golden Ratio won't be calculated) "; string stdInput; cin >> stdInput;
    // Convert the string to an integer
    try { maxFibonacci = stoi(stdInput); }
    // If out_of_range or invalid_argument exception is catched, display an error message and some help 
    catch (out_of_range) { cout << "\n--- Number too big! ---\nHowever you could try to hardcode the value into the 'maxFibonacci' macro, after commenting the lines indicated in the code.\n"; return -1; }
    catch (invalid_argument) { cout << "\n--- Invalid input! ---\nAre you sure that your input is an integer?\n"; return -1; }
    // ------------------------------------------------------------------------

    // Define the Fibonacci numbers holders
    int1024_t secLastFib;
    int1024_t lastFib;

    // Declare the first Fibonacci numbers
    secLastFib = 1;
    lastFib = 1;
    
    // Display the 3 firsts hardcoded Fibonacci numbers
    cout << "0\n1\n1\n";

    while (lastFib < maxFibonacci || maxFibonacci == -1) {
        // Calculate Fibonacci numbers
        int1024_t fib = ((lastFib)+(secLastFib));
        // If the calculated Fibonacci is bigger than the max Fibonacci to calculate exit the loop
        if (fib > maxFibonacci && maxFibonacci != -1) { break; }
        // Move the values
        secLastFib = lastFib;
        lastFib = fib;

        // Show the Fibonacci number on stdout
        cout << lastFib << "\n";

        // Uncoment the following line if you want to make the calculation of the Fibonacci sequence slower
        // usleep(10000);
    }

    cout << "Calculated golden ratio ( " << lastFib << " / " << secLastFib << "): ";
    
    // Calculate the Golden Ratio with the latests Fibonacci numbers in the sequence calculated
    cpp_dec_float_100 goldenRatio = (static_cast<cpp_dec_float_100>(lastFib) / static_cast<cpp_dec_float_100>(secLastFib));

    // Show the calculated Golden Ratio on stdout
    cout << setprecision(numeric_limits<cpp_dec_float_100>::digits10) << goldenRatio << "\n";

    return 0;
}
