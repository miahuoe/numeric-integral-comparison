#!/usr/bin/sh

i=0
while test -f "rect_test_f_$i.csv"
do
	csv_file="rect_test_f_$i.csv"
	png_file="rect_test_f_$i.png"
	gnuplot -e "csv_file='$csv_file'; png_file='$png_file'" rect_test.gnuplot
	echo "$png_file"
	(( i = i + 1 ))
done
