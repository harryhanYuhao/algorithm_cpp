#!/bin/bash 

RED='\033[0;31m'
BOLD='\033[1m'
NOCOLOR='\033[0m'

HELP() {
	echo -e "run.bash script for algorithm_cpp"
	echo -e "Usage: bash run.bash [OPTIONS]"
	echo -e "Options:" 
	echo -e "  -h, --help, help  Display this help and exit"
	echo -e "  -r, --run, run    Compile and run the algorithm_cpp"
	echo -e "  -C, --compile, compile  Compile the algorithm_cpp"
	echo -e "  -c, --clean, clean  Clean the algorithm_cpp"

}

COMPILE() {
	cmake -S . -B build
	cmake --build build
}

RUN() {
	COMPILE
	echo -e "${RED}${BOLD}OUTPUT of a.out:${NOCOLOR}"
	./build/a.out
}

CLEAN() {
	echo -e "${RED}${BOLD}Removing the build directory${NOCOLOR}"
	rm -rf build
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
		-h|--help|help)
			HELP
			exit 0
			;;
		-r|--run|run)
			RUN
			exit 0
			;;
		-C|--compile|compile)
			COMPILE
			exit 0
			;;
		-c|--clean|clean)
			CLEAN
			exit 0
			;;
		*)
			echo "Unknown option: $key"
			exit 1
			;;
	esac
done
