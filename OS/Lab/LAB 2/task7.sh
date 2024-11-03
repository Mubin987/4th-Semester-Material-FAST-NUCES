#!/bin/bash
fact() {
  local n=$1
  local a=0
  local factorial=1


  for (( i=1; i<=n; i++ ));
   do
   factorial=$((factorial * i))
    
  done
  echo  " $factorial "
  
}


read -p "Enter the number to fid its factorial: " num


fact $num
