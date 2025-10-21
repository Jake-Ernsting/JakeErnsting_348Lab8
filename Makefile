CC	:= gcc
CFLAGS	:= -std=cll -Wall -Wextra -Wpedantic -O2

PROGS	:= NFL_score_tracker Temp_Converter

all: $(PROGS)

NFL_score_tracker: NFL_score_tracker.c
	$(CC) $(CFLAGS) $< -o $@ 

Temp_Converter: Temp_Converter.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean run1 run2
run1: NFL_score_tracker
	./NFL_score_tracker

run2: Temp_Converter
	./Temp_Converter

clean:
	rm -f $(PROGS) *.o