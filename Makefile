sjon: sjon.c
	gcc sjon.c -c bin/sjon

install: sjon
	cp bin/sjon /usr/local/bin/

.PHONY: install
