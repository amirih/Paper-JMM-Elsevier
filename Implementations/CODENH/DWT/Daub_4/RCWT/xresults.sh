#!/bin/bash
cd "col"
echo $PWD
sh result.sh
cd ..

cd "colunroll1"
echo $PWD
sh result.sh
cd ..

cd "colunroll2"
echo $PWD
sh result.sh
cd ..

cd "row"
echo $PWD
sh result.sh
cd ..

cd "rowunroll1"
echo $PWD
sh result.sh
cd ..

cd "rowunroll2"
echo $PWD
sh result.sh
cd ..

cd "fullfilter"
echo $PWD
sh result.sh
cd ..



cd "fullfilterunroll2"
echo $PWD
sh result.sh
cd ..
