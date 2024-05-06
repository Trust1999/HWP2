#include <iostream>
#include <fstream>
#include <b15f/b15f.h>

double to_floating_voltage(uint16_t val) {
  return static_cast<double>(val) / 1023.0 * 5.0;
}

uint16_t to_uint_voltage(double val) {
  return static_cast<uint16_t>(val / 5.0 * 1023);
}

std::vector<double> measure(B15F& drv, double voltage_0, double voltage_1) {
  drv.analogWrite0(to_uint_voltage(voltage_0));
  drv.analogWrite1(to_uint_voltage(voltage_1));

  std::vector<double> output = {0.0, 0.0, 0.0, 0.0};
  uint8_t index = 0;
  for (auto& result : output) {
    result = to_floating_voltage(drv.analogRead(index));
    index += 1;
  }
  return output;
}

int main() {
  B15F& drv = B15F::getInstance();

  std::cout << "Name of component: ";
  std::string name;
  std::getline(std::cin, name);

  std::cout << "Resistance: ";
  std::string resistance_string;
  std::getline(std::cin, resistance_string);
  double resistance = stod(resistance_string);

  std::array<double, 9> voltages_1 = { 0.0, 1.0, 2.0, 2.2, 2.5, 2.7, 3.0, 4.0, 5.0 };
  
  for (auto voltage_1 : voltages_1) {
    std::ofstream csv_file;
    csv_file.open("./data/" + name + std::to_string(static_cast<uint8_t>(voltage_1 * 10.0)) + ".csv");
    csv_file << "# in0; in1; out0; out1; out2; out3; currentDrain\n";

    for (double voltage_0 = 0.0; voltage_0 <= 5.0; voltage_0 += 0.5) {
      auto output = measure(drv, voltage_0, voltage_1);
      output.push_back((output[0] - output[1]) / resistance);
    std::cout
      << "In: (" << voltage_0 << ", " << voltage_1 << "), "
      << "Out: (" << output[0] << ", " << output[1] << ", " << output[2] << ", " << output[3] << "), "
      << "Current Drain: (" << output[4] << ")\n";
    csv_file
      << voltage_0 << ";" << voltage_1 << ";"
      << output[0] << ";" << output[1] << ";" << output[2] << ";" << output[3] << ";"
      << output[4] << "\n";
    }
  }
}
