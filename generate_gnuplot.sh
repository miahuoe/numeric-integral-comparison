#!/usr/bin/bash

if [ $# -lt 2 ]
then
	echo "Usage: $(basename $0) prefix columns..."
	exit
fi

generate_gnuplot() {
	file="/tmp/plot.$$.gnuplot"
	colors=('#ff0000' '#00ff00' '#0000ff' '#ff00ff' '#ffff00' '#00ffff')

	cat << EOF > $file
set term png
set datafile separator ","
set output png_file
set grid ytics mytics
set grid xtics mxtics
EOF

	echo -n "set style line 99 linecolor rgb '#000000' " >> $file
	echo -n "linetype 1 linewidth 2 pointtype 0 pointsize 1; " >> $file

	for cn in `seq $#`; do
		echo -n "set style line $cn linecolor rgb" >> $file
		echo -n " '${colors[$(( cn - 1))]}' linetype 1" >> $file
		echo -n " linewidth 1 pointtype 0 pointsize 1; " >> $file
	done

	echo -n "plot " >> $file

	echo -n "csv_file using \"n\":\"true\" with linespoints " >> $file
	echo -n "linestyle 99 title \"true\"" >> $file

	i=1
	for c in "$@"; do
		echo -n ", " >> $file
		echo -n "csv_file using \"n\":\"$c\" with " >> $file
		echo -n "linespoints linestyle $i title \"$c\"" >> $file
		(( i = i + 1 ))
	done

	echo ";" >> $file

	echo "$file"
}

prefix=$1
columns=${@:2}

i=0
while test -f "${prefix}_f_$i.csv"
do
	csv_file="${prefix}_f_$i.csv"
	png_file="${prefix}_f_$i.png"
	gnuplot_file=$(generate_gnuplot $columns)
	gnuplot -e "csv_file='$csv_file'; png_file='$png_file'" $gnuplot_file
	rm $gnuplot_file
	echo "$png_file"
	(( i = i + 1 ))
done
