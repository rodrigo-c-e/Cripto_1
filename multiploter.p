set title 'Curva de desempeno (Maquina A)'
set multiplot
set style line 1 linecolor rgb '#a2f0fd' linetype 1 linewidth 1 pointtype 1 pointsize 1
set style line 2 linecolor rgb '#ac20fd' linetype 1 linewidth 1 pointtype 1 pointsize 1
set style line 3 linecolor rgb '#b42a0d' linetype 1 linewidth 1 pointtype 1 pointsize 1
set style line 4 linecolor rgb '#b54a0d' linetype 1 linewidth 1 pointtype 1 pointsize 1
set style line 5 linecolor rgb '#b64a0d' linetype 1 linewidth 1 pointtype 1 pointsize 1
set sample 19
set xrange [10:60]
set yrange [0:0.00015]
set xlabel 'n'
set ylabel 'Execution Time (secs)'
set xtics nomirror
set key at 59,0.00015
plot "data1" using 1:2 t 'Algorithm 1' with linespoints linestyle 1
set key at 59,0.00014
plot "data2" using 1:2 t 'Algorithm 2' with linespoints linestyle 2
set key at 59, 0.00013
plot "data3" using 1:2 t 'Algorithm 3' with linespoints linestyle 3
set key at 59, 0.00012
plot "data4" using 1:2 t 'Algorithm 4' with linespoints linestyle 4
set key at 59, 0.00010
plot "data5" using 1:2 t 'Algorithm 5' with linespoints linestyle 5
pause -1
