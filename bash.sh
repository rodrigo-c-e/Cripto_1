#!/bin/bash

# Define the range of values for V1 and V2
rm -rf data* exe*

V1_values=(291 16261 139024789 5618 975182 198478 91723 47824 97510 4718 862893 537291 838 71642 84724 8192 126392 927481 82728)
V2_values=(252 85652 93278890 84628 773481 4718393 572648 2994714 18645639 182646134 17242 17273 2727 8633 182619 497182 8261 8281 899)

# Compile programs and create exe 
gcc -o exe1 GCD_Sustraccion.c
gcc -o exe2 GCD.c
gcc -o exe3 GCD_Binario.c
gcc -o exe4 GCD_Extendido.c
gcc -o exe5 GCD_Extendido_Bin.c

# Loop through each combination of V1 and V2
for i in {0..18}; do
	V1=${V1_values[$i]}
	V2=${V2_values[$i]}
	
	# Show values to evaluate
	for j in {1..5}; do
		./exe$j $V1 $V2 >> data$j
	done		
done

for j in {1..5}; do
	sort -k 1 -n data$j -o data$j
	gnuplot ploter$j.p
done
exit
	

