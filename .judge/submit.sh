# sh .judge/judge.sh 10038 lucetre/chap02/10038/main.cpp
prob="testcase/$1"
code=${2##*/}

echo "\n$1: $2\n-------------"
cp "$2" .judge/
cd .judge

if [ ${code##*.} = 'java' ]
then
  javac $code

  for file in $prob/*.testin
  do
      name=${file##*/}
      tc=${name%.testin}
      
      echo "TESTCASE #$tc"
      java ${code%.java} < $prob/$tc.testin > $prob/$tc.out
      diff $prob/$tc.out $prob/$tc.testout -b
      res=$(diff $prob/$tc.out $prob/$tc.testout -b | wc -l)

      if [ $res -eq 0 ]
      then
        echo "✓ PASS\n-------------"
      else
        echo "✗ WRONG\n-------------"
        exit 1
    fi
  done
elif [ ${code##*.} = 'cpp' ]
then
  g++ $code

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
        exit 1
    fi
  done
fi
