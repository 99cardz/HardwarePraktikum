set margin 10,10
unset key
set grid
set title ''
set xlabel 'x-Achse [N/D]'
set ylabel 'U [N/D]'
set xrange [0:102]
set yrange [0:5]
set label at 101,4 '0' left
unset output 
set terminal qt
unset output
plot "/tmp/tempfile1" using ($1*0.099707):($2*0.004888) binary format="%int16%int16" endian=big title ' [] = 0' w l
