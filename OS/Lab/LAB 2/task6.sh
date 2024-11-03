#!/bin/bash
fib() {
  local n=$1
  local a=0
  local b=1
  local fib=0

  for (( i=0; i<n; i++ ));
   do
    if [ $i -le 1 ];
     then
      fib=$i
    else
      fib=$((a + b))
      a=$b
      b=$fib
    fi
    echo  "$fib "
  done
  
}


read -p "Enter the number of terms: " num


fib $num
