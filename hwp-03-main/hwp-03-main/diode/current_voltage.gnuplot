set datafile separator ";"
set grid

set xlabel "U_D_i_o_d_e [V]"
set ylabel "I_G [A]"

plot "./data/red_led.csv" using 3:4 title "Rote LED" smooth bezier, \
     "./data/small_black.csv" using 3:4 title "Klein Schwarz" smooth bezier, \
     "./data/silver.csv" using 3:4 title "Silber" smooth bezier, \
     "./data/red_head.csv" using 3:4 title "Red Head" smooth bezier, \
     "./data/ugly_apple.csv" using 3:4 title "Hässlich" smooth bezier, \
     "./data/red_tube.csv" using 3:4 title "Rote Röhre" smooth bezier
