#include <iostream>
#include <b15f/b15f.h>


int main() {
  B15F& drv = B15F::getInstance();

  drv.analogWrite0(1023);
  while(true) {
    drv.analogWrite1(1023);
    drv.delay_ms(50);
    drv.anlaogWrite1(0);
    drv.delay_ms(50);
  }

}
