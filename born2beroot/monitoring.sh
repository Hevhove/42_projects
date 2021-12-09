# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    monitoring.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 17:16:51 by hvan-hov          #+#    #+#              #
#    Updated: 2021/12/09 17:17:07 by hvan-hov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Monitoring.sh script for Born2BeRoot
# The purpose of this script is to show a number of statistics to the user every 10 minutes
#!bin/bash

# VARIABLES
arc=$(uname -a)
pcpu=$(lscpu | awk 'NR == 5 {print $2}')
vcpu=$(cat /proc/cpuinfo | grep processor | wc -l)
freemem=$(free -m | awk 'NR == 2 {print $3}')
totalmem=$(free -m | awk 'NR == 2 {print $2}')
memusage=$(echo "scale=5; $freemem/$totalmem * 100" | bc)
memusagr=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
totaldisk=$(df -h | awk 'NR == 4 {print $2}')
freedisk=$(df -h | awk 'NR == 4 {print $3}')
diskusage=$(df -h | awk 'NR == 4 {print $5}')
cpuusage=$(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage ""}')
cpuusagr=`printf "%.2f" $cpuusage`
lb=$(who -b | awk '{print $3, $4, $5}')
lvmt=$(lsblk | grep "lvm" | wc -l)
lvmu=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -s | awk 'NR == 2 {print $4}' | sed 's/.$//')
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | awk 'NR == 4 {print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

# MESSAGE
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $freemem/${totalmem}MB ($memusagr%)
	#Disk Usage: $freedisk/${totaldisk} (${diskusage})
	#CPU load: ${cpuusagr}%
	#Last boot: $lb
	#LVM use: $lvmu
	#Connexions TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
