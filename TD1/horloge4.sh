#!/bin/bash
set `date`
for i in *.TZ
do
  var=`cat $i`
  var=`zdump $var`
  var=`echo $var | cut -d' ' -f5`
  echo "Nous sommes le $3 $2 $6, il est : $var"
done
