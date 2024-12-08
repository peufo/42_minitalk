#!/bin/bash

info() {
	echo -e "\033[36m$1\033[0m"
}
warning() {
	echo -e "\033[31m$1\033[0m"
}
success() {
	echo -e "\033[32m$1\033[0m"
}

watch() {
	STATE_A=""
	while [[ true ]]
	do
		STATE_B=$(get_state)
		if [[ $STATE_A != $STATE_B ]]; then
			STATE_A=$STATE_B
			clear
			info "HEY BRO 👋 $(date)"
			./sync.sh

			NORM_ERROR=$(sed -e '/.*: OK!/d' <(norminette))
			if [[ $NORM_ERROR == "" ]] ; then
				success "\nNORMINETTE OK\n"
			else
				warning "\nNORMINETTE ERROR"
				echo "$NORM_ERROR\n"
			fi

			CLIENT="./client"
			SERVER="./server"

			rm -f "$CLIENT"
			rm -f "$SERVER"
			make
			if [ ! -f "$CLIENT" -o ! -f "$SERVER" ]; then
				warning "COMPILATION FAILED"
			else
				success "COMPILATION OK"
			fi
		fi
		sleep 0.1
	done
}

get_state() {
	if [[ $(uname) == "Linux" ]];  then
		MD5="md5sum"
	else
		MD5="md5"
	fi
	echo $(find -L . -type f -name "*.[ch]" -exec $MD5 {} \;)
}

watch
