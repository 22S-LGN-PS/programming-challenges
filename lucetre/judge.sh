cd lucetre/judge
g++ main.cpp

for file in testcase/*.testin
do
    filename=${file##*/}
    tc=${filename%.testin}
    
    echo "TESTCASE #$tc"
    ./a.out < testcase/$tc.testin > testcase/$tc.out
    diff testcase/$tc.out testcase/$tc.testout -b
    res=$(diff testcase/$tc.out testcase/$tc.testout -b | wc -l)

    if [ $res -eq 0 ]
	then
		echo "PASS"
    else
    	echo "WRONG"
	fi
done