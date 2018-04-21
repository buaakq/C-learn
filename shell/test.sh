#!/bin/bash

print_max()
{
   if [ $# -eq 0 ]; then
      return 1
   fi
   MAX=$1
   for NUM in $@; do
      if [ "$NUM" -gt $MAX ]; then
         MAX="$NUM"
      fi
   done
   echo "$MAX"
   return 0
}

echo "$#"

if [ "$#" != 2 ]; then
   echo "usage wrong"
fi

INPUT="yes"
if [ "$INPUT" = "yes" ]; then
   echo "good morning"
elif [ "$INPUT" = "no" ]; then
   echo "good evening"
else
   echo "bye bye"
fi

COUNTER=1
while [ "$COUNTER" -le "10" ]; do
   echo "number = $COUNTER"
   COUNTER=$(($COUNTER+1))
done

echo $$

print_max 1 2 3 4 0 10 8 11

exit 0
