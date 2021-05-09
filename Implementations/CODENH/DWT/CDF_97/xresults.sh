#!/bin/bash
cd "col"
echo $PWD
sh result.sh
cd ..

cd "row"
echo $PWD
sh result.sh
cd ..

cd "fullfilter"
echo $PWD
sh result.sh
cd ..

cd "fullfilterLPI"
echo $PWD
sh result.sh
cd ..

cd "Transpose"
echo $PWD
sh result.sh
cd ..

cd "TransposeLPI"
echo $PWD
sh result.sh
cd ..
