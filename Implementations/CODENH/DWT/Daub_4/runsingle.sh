#!/bin/bash

cd "/home/martin/Desktop/Come with me/I am organized here/header files/"
DIM=128
echo "#define MAXD " $DIM > file.h
cd "/home/martin/Desktop/Come with me/I am organized here/000 - My Atricles/001 - JMM - revision/Implementatios.JMM/CODENH/DWT/Daub_4"
sh xresults.sh

cd "/home/martin/Desktop/Come with me/I am organized here/header files/"
DIM=256
echo "#define MAXD " $DIM > file.h
cd "/home/martin/Desktop/Come with me/I am organized here/000 - My Atricles/001 - JMM - revision/Implementatios.JMM/CODENH/DWT/Daub_4"
sh xresults.sh

cd "/home/martin/Desktop/Come with me/I am organized here/header files/"
DIM=512
echo "#define MAXD " $DIM > file.h
cd "/home/martin/Desktop/Come with me/I am organized here/000 - My Atricles/001 - JMM - revision/Implementatios.JMM/CODENH/DWT/Daub_4"
sh xresults.sh

cd "/home/martin/Desktop/Come with me/I am organized here/header files/"
DIM=1024
echo "#define MAXD " $DIM > file.h
cd "/home/martin/Desktop/Come with me/I am organized here/000 - My Atricles/001 - JMM - revision/Implementatios.JMM/CODENH/DWT/Daub_4"
sh xresults.sh
