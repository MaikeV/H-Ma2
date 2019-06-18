reset
set terminal canvas
set datafile separator "\t"
set autoscale x
set autoscale y
set xlabel "n[-]"
set ylabel "t[ms]"
set key top left
set key font ",12"
set xtics font ",10"

set output 'PlotOrig.html'

plot \
"Daten_original.txt" every ::1 using 1:2 with linespoints title 'DatenOriginal' linetype 0 linecolor rgb "dark-red",\

