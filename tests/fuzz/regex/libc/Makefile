CC=clang
CFLAGS=-g -O1 -fsanitize=fuzzer,address,undefined
TARGET=regexec regcomp

all: ${TARGET}
fuzz-regexec: regexec
	./regexec -only_ascii=1 -dict=dict ./regexec-input > /dev/null
fuzz-regcomp: regcomp
	./regcomp -only_ascii=1 -dict=dict ./regcomp-input > /dev/null

clean:
	rm -f ${TARGET} *.o
