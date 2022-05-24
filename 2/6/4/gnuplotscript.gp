set margin 10,10
unset key
set grid
set title ''
set xlabel 'U_{Gate} [V]'
set ylabel 'I_{Drain} [mA]'
set xrange [0:5]
set yrange [0:1]
unset output 
set terminal qt
unset output
plot "/tmp/tempfile20" using ($1*0.004888):($2*0.000978) binary format="%int16%int16" endian=big title ' [] = 1' w l,"/tmp/tempfile30" using ($1*0.004888):($2*0.000978) binary format="%int16%int16" endian=big title ' [] = 2' w l,"/tmp/tempfile40" using ($1*0.004888):($2*0.000978) binary format="%int16%int16" endian=big title ' [] = 3' w l
