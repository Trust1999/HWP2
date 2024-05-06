set datafile separator ";"
set grid

set xlabel "U_A_A_0 [V]"
set ylabel "U_A_E_0 [V]"

plot "./data/1000.csv" using 1:3 title "1000 Ohm" smooth bezier, \
     "./data/100.csv" using 1:3 title "100 Ohm" smooth bezier, \