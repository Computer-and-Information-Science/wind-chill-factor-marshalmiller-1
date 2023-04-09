// Wind Chill Factor, Instructor's Solution
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double ctof (double c);
double ftoc (double f);
double windchill (double temperature, double velocity);

int main () {
  double temp;    // Temperature, input
  char scale;      // Temperature scale, input, 'c' or 'f'
  double wind;    // Wind speed in MPH, input

  double wcf;      // Wind chill factor, in Fahrenheit

  cout << fixed << setprecision(1);

  // Get the temperature, scale, and wind speed.
  cout << "Enter temperature: ";
  cin >> temp;
  cout << "Enter scale (f or c): ";
  cin >> scale;
  cout << "Enter wind speed: ";
  cin >> wind;

  // Calculate the wind chill factor.
  if (scale == 'f') // If Fahrenheit
    wcf = windchill(temp, wind);
  else // Input in Celsius, convert to Fahrenheit before calling windchill.
    wcf = windchill(ctof(temp), wind);

  // Output in original scale.
  if (scale == 'f')
    cout << "Wind chill factor is " << wcf << "F." << endl;
  else
    cout << "Wind chill factor is " << ftoc(wcf) << "C." << endl;

  return 0;
}

double ctof (double c) {
  return 9.0 / 5 * c + 32;
}

double ftoc (double f) {
  return 5.0 / 9 * (f - 32);
}

double windchill (double temperature, double velocity) {
  return 35.74 +
    0.6215 * temperature -
    35.75 * pow(velocity, 0.16) +
    0.4275 * temperature * pow(velocity, 0.16);
}
