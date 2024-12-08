#!/bin/sh

sync() {

	#SYNC Makefile SOURCES
	CLIENT_SOURCES=$(ls src/client/*.c | sed 's;src/client/;;g' | tr '\n' ' ')
	SERVER_SOURCES=$(ls src/server/*.c | sed 's;src/server/;;g' | tr '\n' ' ')

	SED_CLIENT_COMMAND="s;^CLIENT_SOURCES	.*;CLIENT_SOURCES		=	$CLIENT_SOURCES;"
	SED_SERVER_COMMAND="s;^SERVER_SOURCES	.*;SERVER_SOURCES		=	$SERVER_SOURCES;"
	if [ $(uname) = "Linux" ];  then
		sed -i -e "$SED_CLIENT_COMMAND" Makefile
		sed -i -e "$SED_SERVER_COMMAND" Makefile
	else
		sed -i "" "$SED_CLIENT_COMMAND" Makefile
		sed -i "" "$SED_SERVER_COMMAND" Makefile
	fi
}

sync "$@"
