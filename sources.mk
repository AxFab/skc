#      This file is part of the SmokeOS project.
#  Copyright (C) 2015  <Fabien Bavent>
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Affero General Public License as
#  published by the Free Software Foundation, either version 3 of the
#  License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Affero General Public License for more details.
#
#  You should have received a copy of the GNU Affero General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
# -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
NAME = SmokeOS_Libc

# F L A G S -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
CFLAGS += -Wall -Wextra -Wno-unused-parameter -fno-builtin
# CFLAGS += -ggdb3 
# CFLAGS += -pedantic
CFLAGS += -D_DATE_=\"'$(DATE)'\" -D_OSNAME_=\"'$(LINUX)'\"
CFLAGS += -D_GITH_=\"'$(GIT)'\" -D_VTAG_=\"'$(VERSION)'\"
CFLAGS += -D__USE_SCALL=1 -D__USE_EXT=1

CFLAGS += -I $(topdir)/include 
# CFLAGS += -I $(topdir)/include/lib/core -I $(topdir)/include/lib/cdefs -nostdinc
CFLAGS += -I $(topdir)/include/asm/$(target_arch)-$(CC)
# CFLAGS += -I $(topdir)/../kernel/include
# CFLAGS += -I $(topdir)/../kernel/include/_$(target_arch)

LFLAGS += -nostdlib

std_CFLAGS := $(CFLAGS)
$(eval $(call ccpl,std))

# T A R G E T S -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
# skc
skc_src-y += $(wildcard $(srcdir)/c89/*.c)
skc_src-y += $(wildcard $(srcdir)/ext/*.c)
skc_src-y += $(srcdir)/crt/int64.c
skc_src-y += $(wildcard $(srcdir)/crt/$(target_os)/*.c)
DV_LIBS += $(libdir)/libskc.so $(libdir)/libskc.a

skc_LFLAGS := $(LFLAGS)
skm_LFLAGS := $(LFLAGS)

$(eval $(call llib,skc,std))
$(eval $(call crt,crt/$(target_os)/crt0,crt0))

