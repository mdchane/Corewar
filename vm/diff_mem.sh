#!/bin/sh

let "i = 0"
./Corewar-info/corewar -d $i $1 $2 $3 $4 $5 > zaz.out
./corewar -dump $i $1 $2 $3 $4 $5 > my.out
diff zaz.out my.out > diff.out
while [ 42 ]
do
	echo $i
	if [ -s diff.out ]
	then
		cat diff.out
		break
	else
		grep -q 'won' 'my.out'
		if [ $? -eq 0 ]
		then
			echo "Test OK"
			break
		fi
		let "i += 1"
		./Corewar-info/corewar -d $i $1 $2 $3 $4 $5 > zaz.out
		./corewar -dump $i $1 $2 $3 $4 $5 > my.out
		diff zaz.out my.out > diff.out
	fi
done
