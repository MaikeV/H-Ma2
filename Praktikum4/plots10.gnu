reset
set terminal canvas
set datafile separator "\t"
set autoscale x
set autoscale y
set xlabel "Re"
set ylabel "Index"
set key top left
set key font ",12"
set xtics font ",10"

set output 'Plot10.html'

plot \
"Daten_original.txt" every ::1 using 1:2 with linespoints title 'DatenOriginal' linetype 0 linecolor rgb "dark-red",\
"10Backtrans.txt" every ::1 using 1:2 with linespoints title 'Epsilon = 1.0' linetype 0 linecolor rgb "blue",\

