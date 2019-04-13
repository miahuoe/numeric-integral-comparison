#!/usr/bin/gnuplot -p
set term png
set datafile separator ","
set output png_file

set style line 1 \
	linecolor rgb '#ff0000' \
	linetype 1 \
	linewidth 1 \
	pointtype 0 \
	pointsize 1;

set style line 2 \
	linecolor rgb '#00ff00' \
	linetype 1 \
	linewidth 1 \
	pointtype 0 \
	pointsize 1;

set style line 3 \
	linecolor rgb '#0000ff' \
	linetype 1 \
	linewidth 1 \
	pointtype 0 \
	pointsize 1;

set style line 4 \
	linecolor rgb '#ff00ff' \
	linetype 1 \
	linewidth 1 \
	pointtype 0 \
	pointsize 1;

#set arrow 1 from 1,164 to 100,164 nohead filled back lw 3 lc rgb "pink"

plot \
	csv_file using "n":"true" \
	with linespoints linestyle 4 \
	title "true", \
	csv_file using "n":"left" \
	with linespoints linestyle 1 \
	title "left", \
	csv_file using "n":"middle" \
	with linespoints linestyle 2 \
	title "middle", \
	csv_file using "n":"right" \
	with linespoints linestyle 3 \
	title "right";

