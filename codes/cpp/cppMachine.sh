#!/bin/bash
FNAME=$1
MODE=$2

if [ $MODE=="create" ]
then
	echo "mode create"
elif [ $MODE=="run" ]
then 
	echo "mode run"
fi
