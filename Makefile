# NAME:Jake Ernsting
# KU ID: 3144926
# DATE: 10/21/2025
# PROGRAM: EECS 348 Lab 8 - Makefile
# DESCRIPTION: Makefile to compile and run NFL score tracker and temperature converter programs.
# SOURCES: ChatGPT & VSCode co-pilot 


CC	:= gcc	# C compiler
CFLAGS	:= -std=cll -Wall -Wextra -Wpedantic -O2	# Compiler flags
PROGS	:= NFL_score_tracker Temp_Converter		# Programs to build

all: $(PROGS)	# Build both programs

# Build NFL score tracker
NFL_score_tracker: NFL_score_tracker.c	
	$(CC) $(CFLAGS) $< -o $@ 

# Build temperature converter
Temp_Converter: Temp_Converter.c
	$(CC) $(CFLAGS) $< -o $@

# Run targets
.PHONY: clean run1 run2
run1: NFL_score_tracker
	./NFL_score_tracker

run2: Temp_Converter
	./Temp_Converter

clean:
	rm -f $(PROGS) *.o