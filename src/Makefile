#
#
#

include $(GOROOT)/src/Make.$(GOARCH)

TARG=pg

CGOFILES=pg.go
CGO_LDFLAGS=pg_wrapper.o -lpq
CLEANERFILES+=runner

include $(GOROOT)/src/Make.pkg

all: runner

runner: pg_wrapper.o install runner.go
	$(GC) runner.go
	$(LD) -o $@ runner.$O

pg_wrapper.o: pg_wrapper.c
	gcc -fPIC -O2 -o pg_wrapper.o -c pg_wrapper.c

