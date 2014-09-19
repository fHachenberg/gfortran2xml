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

SHELL=/bin/sh

GFORTRAN2XML=../gfortran2xml
# file names WITHOUT the extension so we can use the same base name
# for the xml files, etc.
TEST_FILES=helloWorld bug1 cdbtf2 cdbtrf csteqr2 ddbtf2 farrays \
           interface1 interface2 interface particle pcgbtrs \
           pclacon pcpocon pdlacon pdlaed2 pdlaed3 pdpotri pjlaenv \
           pslacon pslaed2 pslaed3 pzlacon receive returns trash \
           particle2 LinearFunction RandNumGenerator \
           MonteCarloIntegrator

PTD_EXT=ptd
XMLTMP_EXT=xml.tmp
XMLCORRECT_EXT=xml.correct

all: runtests

runtests: .FAKE
	@for file in $(TEST_FILES) ; do \
          echo "testing gfortran2xml with file " $$file.$(PTD_EXT) ; \
          $(GFORTRAN2XML) < $$file.$(PTD_EXT) > $$file.$(XMLTMP_EXT) ; \
          if diff $$file.$(XMLTMP_EXT) $$file.$(XMLCORRECT_EXT) ; \
          then \
            echo "files are the same" ; \
          else \
            echo "Files differ: " $$file.$(XMLTMP_EXT) $$file.$(XMLCORRECT_EXT) ; \
          fi ; \
        done

.FAKE:

clean:
	@for file in $(TEST_FILES) ; do \
          echo "deleting file " $$file.$(XMLTMP_EXT) ; \
          rm -f $$file.$(XMLTMP_EXT) ; \
        done

