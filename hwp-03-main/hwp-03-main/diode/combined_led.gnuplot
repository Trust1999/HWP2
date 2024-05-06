set datafile separator ";"

set xlabel "U_A_A_0 [V]"
set ylabel "U_A_E_0 [V]"
set y2label "I_G [A]"
set y2range [0:0.002]
set y2tics autofreq

plot "./data/red_led.csv" using 1:3 axis x1y1 title 'Voltage' smooth bezier, \
     "./data/red_led.csv" using 1:4 axis x1y2 title 'Current' smooth bezier
