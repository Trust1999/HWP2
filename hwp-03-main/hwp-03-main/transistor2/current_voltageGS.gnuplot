set datafile separator ";"
set grid

set xlabel "U_A_E_1 [V]"
set ylabel "I_D [V]"

plot "./data/transistor20.csv" using 5:7 title "2.0 V" smooth bezier, \
     "./data/transistor30.csv" using 5:7 title "3.0 V" smooth bezier, \
     "./data/transistor40.csv" using 5:7 title "4.0 V" smooth bezier, \
     "./data/transistor50.csv" using 5:7 title "5.0 V" smooth bezier, \