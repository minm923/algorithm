#!/bin/bash

FILES1=`ls`
FILES2=$(ls)

ARR=("Hello" "World")

echo ${ARR[0]}
echo ${ARR[1]}
echo ${ARR[*]}
echo ${ARR[@]}
echo ${#ARR[*]}
echo ${#ARR[@]}

echo "for test start"
for elmt in ${ARR[*]}
do
    echo $elmt    
done    

for ((i=0;i<=4;++i))
do
    printf "%d \n" $i
done

for FILE in `ls`
do
    echo $FILE
done    

for var in gao min xu yue
do
    echo $var
done

echo "for test end"

echo "while test start"
i=0
j=0

while(((i<10)&&(j<4)))
do
    echo $i
    ((i=i+1))
    ((j=j+1))
done    
echo "while test end"


if (($i <10)) 
then
    echo "gaomin"
else    
    echo "xuyue"
fi    

DATA=my
STR="cat $DATA"
eval $STR

MYSQL="mysql -uroot -p123456 tw_game"
echo "select * from DBRoleData_9 limit 1" | $MYSQL

