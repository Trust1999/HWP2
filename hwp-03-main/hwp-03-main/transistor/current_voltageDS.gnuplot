set datafile separator ";"
set grid

set xlabel "U_A_E_1 [V]"
set ylabel "I_D [V]"

plot "./data/transistor0.csv" using 4:7 title "0.0 V" smooth bezier, \
     "./data/transistor10.csv" using 4:7 title "1.0 V" smooth bezier, \
     "./data/transistor20.csv" using 4:7 title "2.0 V" smooth bezier, \
     "./data/transistor22.csv" using 4:7 title "2.2 V" smooth bezier, \
     "./data/transistor25.csv" using 4:7 title "2.5 V" smooth bezier, \
     "./data/transistor27.csv" using 4:7 title "2.7 V" smooth bezier, \
     "./data/transistor30.csv" using 4:7 title "3.0 V" smooth bezier