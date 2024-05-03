data = "data2"
stats data using 2 nooutput
set title 'Performance Curve time vs #bits (Machine A)'
set style line 5 linecolor rgb '#ff0000' linetype 1 linewidth 1 pointtype 7 pointsize 0.5
set sample 19
set xrange [0:17]

set xlabel 'n'
set ylabel 'Execution Time (secs)'
set xtics nomirror
set yrange [STATS_min/1.3:STATS_max*1.3]
set key at 59,0.0002
plot data using 1:2 t 'Algorithm 2' with linespoints linestyle 5


set terminal svg
set output "plot2.svg"
replot
pause -1