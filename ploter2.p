set title 'Performance Curve time vs #bits (Machine A)'
set style line 5 linecolor rgb '#ff0000' linetype 1 linewidth 1 pointtype 2 pointsize 1
set sample 19
set xrange [15:60]
set yrange [0.000001:0.0000042]
set xlabel 'n'
set ylabel 'Execution Time (secs)'
set xtics nomirror
set key at 59,0.0002
plot "data2" using 1:2 t 'Algorithm 2' with linespoints linestyle 1
set terminal svg
set output "plot2.svg"
replot
pause -1