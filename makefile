# Make file for Assignment 5

stringDelimiter: heapReport.o stringDelimiterTest.o stringDelimiter.o
	gcc -o stringDelimiter stringDelimiterTest.o heapReport.o stringDelimiter.o 
heapReport.o: heapReport.c heapReport.h
stringDelimiterTest.o: stringDelimiterTest.c
stringDelimiter.o: stringDelimiter.c stringDelimiter.h

# cleans up all non-source files 
cleanup:
	rm -f heapReport.o stringDelimiterTest.o stringDelimiter.o stringDelimiter