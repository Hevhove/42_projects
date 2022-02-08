#!/bin/bash

for i in {1..25}
do
	echo "-|-|-|-|-|-|-|-|-|-|-"
	ARG=`ruby -e "puts (-1000..1000).to_a.shuffle.first(500).join(' ')"`;
	RESULTS=`./push_swap $ARG`
	printf "$RESULTS\n" | ./checker_Mac $ARG
	printf "$RESULTS\n" | wc -l
done
