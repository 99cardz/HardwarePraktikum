set margin 10,10
unset key
set grid
set title ''
set xlabel 'U [V]'
set ylabel 'I [mA]'
set xrange [0:5]
set yrange [0:5]
set label at 4,3 '1' left
unset output 
set terminal qt
unset output
plot "/tmp/tempfile1" using ($1*0.004888):($2*0.004888) binary format="%int16%int16" endian=big title ' [] = 1' w l
