# sh .judge/judge.sh 10038 lucetre/chap02/10038/main.cpp
prob="testcase/$1"
echo "\n$1: $2\n-------------"
cp "$2" .judge/main.cpp
cd .judge
g++ main.cpp

for file in $prob/*.testin
do
    name=${file##*/}
    tc=${name%.testin}
    
    echo "TESTCASE #$tc"
    ./a.out < $prob/$tc.testin > $prob/$tc.out
    diff $prob/$tc.out $prob/$tc.testout -b
    res=$(diff $prob/$tc.out $prob/$tc.testout -b | wc -l)

    if [ $res -eq 0 ]
    then
      echo "✓ PASS\n-------------"
    else
    	echo "✗ WRONG\n-------------"
	fi
done