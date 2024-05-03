set title 'Curva de desempeno (Maquina A)'
set multiplot
set style line 1 linecolor rgb '#a2f0fd' linetype 1 linewidth 1 pointtype 6 pointsize 1
set style line 2 linecolor rgb '#ac20fd' linetype 1 linewidth 1 pointtype 6 pointsize 1
set style line 3 linecolor rgb '#b42a0d' linetype 1 linewidth 1 pointtype 6 pointsize 1
set sample 9
set xrange [0:100]
set yrange [0:0.0001]
set xlabel 'n'
set ylabel 'Execution Time (secs)'
set xtics nomirror
set key at 90,0.00008
plot "resultsiterativo.txt" using 1:2 t 'Algoritmo iterativo' with linespoints linestyle 1
set key at 90,0.00007
plot "resultsmatriz.txt" using 1:2 title 'Algoritmo matriz 2x2' with linespoints linestyle 2
set key at 90,0.00006
plot "resultsrecursivo.txt" using 1:2 title 'Algoritmo recursivo' with linespoints linestyle 3
pause -1
