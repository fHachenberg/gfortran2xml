#
# gfortran2xml v0.6
#
# Copyright (2004). The Regents of the University of California. This material
# was produced under U.S. Government contract W-7405-ENG-36 for Los Alamos
# National Laboratory, which is operated by the University of California for
# the U.S. Department of Energy. The U.S. Government has rights to use,
# reproduce, and distribute this software. NEITHER THE GOVERNMENT NOR THE
# UNIVERSITY MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR ASSUMES ANY LIABILITY
# FOR THE USE OF THIS SOFTWARE. If software is modified to produce derivative
# works, such modified software should be clearly marked, so as not to confuse
# it with the version available from LANL.
#
# Additionally, this program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or (at your
# option) any later version. Accordingly, this program is distributed in the
# hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
# the GNU General Public License for more details.
#
# LA-CC-04-154
# 
ifndef $(CC)
  CC  = cc
endif

SRCS=lex.yy.c ptd-parser.tab.c xml-fortran.c
OBJS=lex.yy.o ptd-parser.tab.o xml-fortran.o

all: gfortran2xml

gfortran2xml: $(OBJS)
	$(CC) -o gfortran2xml $(CFLAGS) $(OBJS)

ptd-parser.tab.o: ptd-parser.tab.h ptd-parser.tab.c
	$(CC) -c -g $(CFLAGS) ptd-parser.tab.c

ptd-parser.tab.c ptd-parser.tab.h: ptd-parser.y
	bison -d --debug --verbose ptd-parser.y

lex.yy.o: lex.yy.c
	$(CC) -c -g $(CFLAGS) lex.yy.c

lex.yy.c: ptd-parser.tab.h ptd-scanner.l
	flex ptd-scanner.l

xml-fortran.o: xml-fortran.c ptd-parser.tab.h
	$(CC) -c -g $(CFLAGS) xml-fortran.c

clean:
	rm -f $(OBJS)  
	rm -f lex.yy.c ptd-parser.output ptd-parser.tab.c \
        ptd-parser.tab.h

allclean:
	$(MAKE) clean
	rm -f gfortran2xml
