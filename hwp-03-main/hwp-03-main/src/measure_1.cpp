#include <iostream>
#include <fstream>
#include <b15f/b15f.h>

double to_floating_voltage(uint16_t int_voltage) {
  return static_cast<double>(int_voltage) / 1023.0 * 5.0;
}

int main() {
  B15F& drv = B15F::getInstance();

  std::cout << "Name of component: ";
  std::string name;
  std::getline(std::cin, name);

  std::ofstream csv_file;
  csv_file.open("./data/" + name + ".csv");
  csv_file << "# in; out; diff; current\n";

  for (uint16_t voltage = 0; voltage <= 1023; voltage += 20) {
    drv.analogWrite0(voltage);
    double in = to_floating_voltage(voltage);
    double out = to_floating_voltage(drv.analogRead(0));
    double voltage_diff = in - out;
    double current = out / 1000.0;
    
    std::cout << "In: " << in << ", Out:" << out << ", Diff:" << voltage_diff << ", Current: " << current << "\n";
    csv_file << in << ";" << out << ";" << voltage_diff << ";" << current << "\n";
  }
}
