OBJ=lcs
SRC=$(wildcard *.cpp *.h)
${OBJ}:${SRC}
	cp S${S}.in S.in
	g++ -g -I. main.cpp -o ${OBJ} -DS${S}
.PHONY:run clean
run:
	./${OBJ} < S.in
clean:
	rm -f ${OBJ} 
