#!/usr/bin/sh

source ./generate_gnuplot.sh

i=0
while test -f "rect_test_f_$i.csv"
do
	csv_file="rect_test_f_$i.csv"
	png_file="rect_test_f_$i.png"
	gnuplot_file=$(generate_gnuplot "left" "middle" "right")
	gnuplot -e "csv_file='$csv_file'; png_file='$png_file'" $gnuplot_file
	rm $gnuplot_file
	echo "$png_file"
	(( i = i + 1 ))
done
