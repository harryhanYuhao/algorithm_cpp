#!/bin/bash 

RED='\033[0;31m'
BOLD='\033[1m'
NOCOLOR='\033[0m'

HELP() {
	echo -e "run.bash script for algorithm_cpp"
	echo -e "Usage: bash run.bash [OPTIONS]"
	echo -e "Options:" 
	echo -e "  -h, --help, help, h    Display this help and exit"
	echo -e "  -r, --run, run, r      Compile and run the algorithm_cpp"
	echo -e "  -b, --build, build, b  Build the algorithm_cpp"
	echo -e "  -c, --clean, clean, c  Clean the algorithm_cpp"
	echo -e "  -t, --test, test, t [args]   Run the test cases"

}

BUILD() {
	cmake -S . -B build
	cmake --build build
}

RUN() {
	BUILD
	echo -e "${RED}${BOLD}OUTPUT of a.out:${NOCOLOR}"
	./build/a.out
}

CLEAN() {
	echo -e "${RED}${BOLD}Removing the build directory${NOCOLOR}"
	rm -rf build
}

TEST() {
	BUILD
	if [ -z "$@" ]; then
		echo -e "${RED}${BOLD}No Input: Running all tests${NOCOLOR}"
		./build/test "*"
		exit 0
	fi
	echo -e "${RED}${BOLD}OUTPUT of ./build/test ${@}: ${NOCOLOR}"
	./build/test "$@"
}

##############################
### START OF EXECUTION
##############################

if [ $# -eq 0 ]; then
	HELP
	exit 1
fi

while [[ $# -gt 0 ]]; do
	key="$1"
	case $key in
		-h|--help|help|h)
			HELP
			exit 0
			;;
		-r|--run|run|r)
			RUN
			exit 0
			;;
		-b|--build|build|b)
			BUILD
			exit 0
			;;
		-c|--clean|clean|c)
			CLEAN
			exit 0
			;;
		-t|--test|test|t)
			TEST ${@:2} # pass all arguments except the first one
			exit 0
			;;
		*)
			echo "Unknown option: $key"
			exit 1
			;;
	esac
done
