```shell
function maria(){
    echo "maria"
}

echo "A"
maria
echo "B"

function raspberrypi(){
    echo "$#"
    echo "$0 $1 $2 $3 $4"
    echo "Fisst:"
    read aNum
    echo "Second"
    read bNum
    echo "A:$aNum----B:$bNum"

    return `expr $aNum + $bNum`
}
raspberrypi 34 56 3 2
echo "The addition is $?"
```



```shell
#!/bin/bash

echo "some simple example . . ."
echo `date`

num1=3
num2=4

if test $[num1]-eq$[num2]:
then
    echo "equal"
else
    echo "not equal"
fi
:<<EOF
#dpkg -i deb(name) install
echo $num1
num1=5
echo $[num1]
echo ${num1}
echo ----
for file in $(ls /home/m/mteaching/module):
do
    echo "file: ${file}"
done
echo ----

name="mteaching"
str="hello, i known you are ${name},haha."
echo $str
str="hello, i known you are $name,haha."
echo $str
str="hello, i known you are \"$name\",haha."
echo -e $str

echo ${#name}

echo `expr index "$name" te`

array=(5 7 6)
echo ${array[1]}
echo ${array[@]}
echo ${#array[*]}
echo ${#array[@]}
EOF

echo "The file's name is: $0"

a=`expr 2 + 2`
echo $a

choose=2
case $choose in
    1) echo "A"
    ;;
    2) echo "B"
    ;;
    *) echo "error"
    ;;
esac

hostname=`uname -n`
echo $hostname
```

