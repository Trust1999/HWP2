#include <iostream>
#include <b15f/b15f.h>


int main() {
  B15F& drv = B15F::getInstance();

  int BE0 = 0;
  int BE1 = 0;
  std::cout<<"BA0 = a, BA1 = b, BE0 = x, BE1 0 = y"
  std::cout<<" b a │ x y "<<"\n";
  std::cout<<"─────┼─────"<<"\n";
  drv . digitalWrite0 (0x0);
  eingang0 = drv.digitalRead0 ();
  eingang1 = drv.digitalRead1 ();
  std::cout<<" 0 0 │ "<<BE0<<" "<<BE1"\n";
  drv.delay_ms(50);
  drv . digitalWrite0 (0x1);
  eingang0 = drv.digitalRead0 ();
  eingang1 = drv.digitalRead1 ();
  std::cout<<" 0 1 │ "<<BE0<<" "<<BE1"\n";
  drv.delay_ms(50);
  drv . digitalWrite0 (0x2);
  eingang0 = drv.digitalRead0 ();
  eingang1 = drv.digitalRead1 ();
  std::cout<<" 1 0 │ "<<BE0<<" "<<BE1"\n";
  drv.delay_ms(50);
  drv . digitalWrite0 (0x3);
  eingang0 = drv.digitalRead0 ();
  eingang1 = drv.digitalRead1 ();
  std::cout<<" 1 1 │ "<<BE0<<" "<<BE1"\n";
  drv.delay_ms(50); 

}
