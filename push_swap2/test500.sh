#!/bin/bash

for i in {1..25}
do
	echo "-|-|-|-|-|-|-|-|-|-|-"
	ARG=`ruby -e "puts (-1000..1000).to_a.shuffle.first(500).join(' ')"`;
	./push_swap $ARG | ./checker_Mac $ARG
	./push_swap $ARG | wc -l
done
