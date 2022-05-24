for i in 2 3 4 5
do
./plot_drainstrom $i > $i_tmp.txt
tail -n +6 $i_tmp.txt > $i.txt
done
