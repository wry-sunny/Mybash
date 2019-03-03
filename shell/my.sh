#!/bin/bash

#echo "hello"

#本地变量
#str="hello world"
#aaa="$str"
#val=100
#echo "str=$str"
#echo "val=$val"
#echo "aaa=$aaa"

#环境变量
#echo "path=$PATH"
#echo "home=$HOME"
#echo "\$0=$0"
#echo "\$#=$#"
#echo "\$$=$$"
#参数变量
#echo "\$1=$1"
#echo "\$2=$2"
#echo "\$3=$3"


#条件
#echo "input:"
#read line

#if test "$line" = "123"
#then
#    echo "=="
#fi

#if [ "$line" = "123" ]
#then
#    echo "=="
#else
#    echo "!="
#fi


#算术比较
#/if [ "$Line" -gt "10" ] && [ "$Line" -lt "100"]
#then
#    echo "10<$line<100"
#else
#    echo "$line<10 || $line >=100"
#fi

#if [ "$line" -lt "0" ] || [ "$line" -gt 100 ]
#then
#    echo "arg err"
#    exit 0
#fi
#
#if [ "$line" -ge "80" ]
#then
#    echo "A"
#elif [ "$line" -ge "70" ]
#then
#    echo "B"
#elif [ "$line" -ge "60" ]
#then
#    echo "C"
#else
#    echo "D"
#fi

#文件测试
#if [ -d "$line" ]
#then
#    echo "this is dirent"
#elif [ -f "$line" ]
#then
#    echo "this is file"
#else
#   echo "no file"
#fi

#循环
#for i in 1 2 3
#do
#    echo i ="$i";
#    sleep 1
#done

#执行一个命令
#str=`ls`
#str=$(ls)
#echo "$str"

#i=1

#while [ : ]
#do
#    echo "input:"
#    read line
#    if [ "$line" = "123" ]
#    then
#        echo "success!"
#        break
#    fi

#    if [ "$i" = 3 ]
#    then
#        exit 1
#    fi
#        let  "i+=1"
#done


#until [ -f main.c ]
#do
#    echo "no main.c!"
#    sleep 1
#done

#echo "find main.c!"


#echo "input:"
#read line

#case $line in
#    yes ) echo "this is yes";;
#    no ) echo "this is no";;
#    * ) echo "****";;
#esac



#while [ : ]
#do
#    echo "input:"
#    read line
    
#    if [ "$line" = "end" ]
#    then
#        break
#    fi

#    case $line in
#        yes | y | Y) echo "this is yes";;
#        no | n | N) echo "this is no";;
#        [Yy][Ee][Ss] | [Yy] ) echo "this is yes";;
#        [Nn][Oo] | [Nn]) echo "this is no";;
#        * ) echo "****";;
#    esac
#done

#1.函数调用
#2.函数传参
fun()
{
    #fun_str="hello world"
    #local：在函数结束之后会撤销掉变量
    local fun_str="hello world"
    echo "fun_str=$fun_str"

    echo "fun run"
    echo "fun \$0=$0"
    echo "fun \$#=$#"
    echo "fun \$1=$1"
    echo "fun \$2=$2"
    
    #撤销掉一个变量
    #unset fun_str

    return 3
}

#echo "main run"
#echo "main \$0=$0"
#echo "main \$#=$#"
#echo "main \$1=$1"
#fun hello abc 123
#echo "val=$?"
#val=$?
#echo "val=$val"
#echo "main : fun_str=$fun_str"



STR="hello world"
#普通到变量是不会传给其他脚本的
#将STR做成一个环境变量
#export STR

#调用另外一个脚本,两个脚本使用的不是同一个解释器
#将STR以传参的形式传出
#./a.sh $STR

echo "my.sh pid="$$""

#./a.sh 产生一个新的解释器 执行a.sh
#. ./a.sh           在当前解释器进行执行
#source ./a.sh      同上

#. ./a.sh
source ./a.sh
echo "my.sh over"









exit 0
