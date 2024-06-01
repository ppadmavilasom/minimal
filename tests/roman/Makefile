build: roman

roman: roman.c
	cc roman.c -o roman

check: build
	./roman 1 | grep -c "I" | grep "1"
	./roman 4 | grep -c "IV" | grep "1"
	./roman 101 | grep -c "CI" | grep "1"
	./roman 25 | grep -c "XXV" | grep "1"
 
clean:
	rm roman

.PHONY: build check clean
