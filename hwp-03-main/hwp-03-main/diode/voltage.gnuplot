set datafile separator ";"
set grid

set xlabel "U_A_A_0 [V]"
set ylabel "U_A_E_0 [V]"

plot "./data/red_led.csv" using 1:2 title "Rote LED" smooth bezier, \
     "./data/small_black.csv" using 1:2 title "Klein Schwarz" smooth bezier, \
     "./data/silver.csv" using 1:2 title "Silber" smooth bezier, \
     "./data/red_head.csv" using 1:2 title "Red Head" smooth bezier, \
     "./data/ugly_apple.csv" using 1:2 title "Hässlich" smooth bezier, \
     "./data/red_tube.csv" using 1:2 title "Rote Röhre" smooth bezier
