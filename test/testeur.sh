#! /bin/bash

test()
{
for i in `seq 1 20`
do
	arg=`shuf -i 1-5000 -n $1 `
	arg=`sed -z 's/\n/ /g' <<<"$arg" `
	ret=`./push_swap $arg`
	if [ "$ret" ]
	then	
		error=`echo "$ret" | ./checker $arg 2>&1`
	else 
		error=`echo -n "$ret" | ./checker $arg 2>&1`
	fi
	echo $error #>>error
	if [[ $error != "OK" ]]
	then 
		 echo $arg >>error
	fi
	ret=`echo "$ret" | wc -l`
	if [[ $ret -ge 0 ]]
	then
		echo " solved in $ret tries"
	fi

done
}

echo "TEST 3========================="
test 3
#sleep 5

echo "TEST 5========================="
test 5
#sleep 5

echo "TEST 10========================="
test 10
#sleep 5

echo "TEST 50========================="
test 50
#sleep 5

echo "TEST 100========================="
test 100
#sleep 5

echo "TEST 200========================="
test 200
#sleep 5

echo "TEST 500========================="
test 500
#sleep 5

echo "TEST 2000========================="
test 2000
#sleep 5

echo "TEST 5000========================="
test 5000
#sleep 5

