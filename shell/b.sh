#!/bin/bash
#awk -F. '{print $1}' file

pid=`ps -f | grep sleep | grep -v "grep" | awk '{print $2}'`

echo "pid=$pid"
if [ -n "$pid" ]
then
    kill "$pid"
fi
exit 0
