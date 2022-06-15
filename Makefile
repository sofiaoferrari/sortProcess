CC=c99
CFLAGS=-Wall -Wextra -pedantic -O0 -ggdb -Wno-unused-parameter
LIBS=-lm -lpthread
all: sortProcess1.out sortProcess2.out sortProcess4.out sortProcess1Serial.out sortProcess2MergeSerial.out

sortProcess1.out: sortProcess1.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

sortProcess2.out: sortProcess2.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

sortProcess4.out: sortProcess4.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

sortProcess1Serial.out: sortProcess1Serial.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

sortProcess2MergeSerial.out: sortProcess2MergeSerial.c common.c common.h
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY: clean
clean:
	rm -f *.o *.out
