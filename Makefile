OBJ=lcs.exe
SRC=$(wildcard *.cpp *.h)
${OBJ}:${SRC} S${S}.in
	cp S${S}.in S.in
	g++ -g -I. main.cpp -o ${OBJ} -DS${S}
.PHONY:run clean
run:
	./${OBJ} < S.in
clean:
	rm -f ${OBJ} 
