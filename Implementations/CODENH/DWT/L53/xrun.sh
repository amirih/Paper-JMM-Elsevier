#!/bin/bash
cd "col"
echo $PWD
sh run.sh
cd ..

cd "row"
echo $PWD
sh run.sh
cd ..

cd "fullfilter"
echo $PWD
sh run.sh
cd ..


cd "fullfilterLPI"
echo $PWD
sh run.sh
cd ..


cd "Transpose"
echo $PWD
sh run.sh
cd ..

cd "TransposeLPI"
echo $PWD
sh run.sh
cd ..
