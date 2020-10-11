############################################################################
# File:     makefile
#
# Purpose:  Makefile for the b64 project,
#           for the Visual C++ 12.0 (x86 UNIXem) compiler,
#           on the UNIX platform
#
# Created:  15th February 2005
# Updated:  11th October 2020
#
############################################################################


############################################################################
# environment check

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG			=	vc12
ARCH_TAG			=	
OS_TAG				=	.unix
PROJ_TAG			=	b64
PROJ_VER_MAJOR		=	1
PROJ_MOD_TAG		=	core
PROJ_TAG_VER		=	$(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

########################################
# dependencies

XTESTS_VER_MAJOR	=	0
XTESTS_TAG_VER		=	xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR	=	1
UNIXEM_TAG_VER		=	unixem.$(XTESTS_VER_MAJOR)

PROJ_MAKEFILE_NAME	=	makefile

########################################
# testing verbosity

!ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
!endif # !TEST_VERBOSITY

############################################################################
# directories

########################################
# project directories

PROJ_BASE_DIR       =   ..\..
PROJ_BIN_DIR        =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR    =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR        =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR        =   .
PROJ_SRC_DIR        =   $(PROJ_BASE_DIR)\src
PROJ_MAPPINGS_DIR   =   $(PROJ_BASE_DIR)\mappings
PROJ_TEST_UNIT_DIR  =   $(PROJ_BASE_DIR)\test\unit
PROJ_EXAMPLES_DIR   =   $(PROJ_BASE_DIR)\examples

########################################
# 3rd-party directories

XTESTS_PROJ_INCLUDE		=	
XTESTS_INCLUDE_DIR	=	$(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR		=	$(PROJ_SRC_DIR)\xtests

############################################################################
# tools

CC                  =   cl
CPPC                =   cl
AR                  =   lib
LD                  =   link
RM                  =   del /f
CP                  =   copy
RC                  =   rc

############################################################
# compiler

########################################
# includes

INCLUDES_LEADER     =   

PROJ_INCLUDE        =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES     =

!ifdef STLSOFT_1_10
STLSOFT_1_10_INCLUDES	=	-I"$(STLSOFT_1_10)\include"
!else # STLSOFT_1_10
STLSOFT_1_10_INCLUDES	=	
!endif # STLSOFT_1_10


STLSOFT_INCLUDES=\
 $(STLSOFT_1_10_INCLUDES)\
 -I"$(STLSOFT)\include"\
 \

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 \

CPPC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(STLSOFT_INCLUDES)\
 \

3PTY_LIBS__DLL_T = \
 \

3PTY_LIBS__MT_T = \
 \

3PTY_LIBS__ST_T = \
 \

3PTY_LIBS__ST_UX_DEBUG = \
 \


LIB_PATHS =\
 \

LIBS_LEADER         =   

COMMON_LIB          =

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DB64_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DUNIX\
	$(CMN_DEF_NO_IMPLICIT_LINK)\
	-DXCONTRACT_NO_USE_WIN_EVENTLOG\
	\

CC_DEFS             =   $(COMMON_DEFS)

CPPC_DEFS           =   $(COMMON_DEFS)

# Flags

CC_F_NOLOGO             =   -nologo
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   
CC_F_WARNING_ERR        =   -WX

CPPC_F_NOLOGO       =   -nologo
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   
CPPC_F_WARNING_ERR  =   -WX
CPPC_F_EXCEPTIONS   =   -GX
CPPC_F_RTTI         =   -GR

CC_TOOL_FLAGS       =

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_DLL_T = -MD -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_T = -MT -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_T = -ML -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_UX_DEBUG = -MLd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_DLL_T = -MD -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_MT_T = -MT -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_T = -ML -U_DEBUG -DB64_VARIANT_TEST -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_UX_DEBUG = -MLd -D_DEBUG -D_STLSOFT_FORCE_ANY_COMPILER -Zi -Fd$*.pdb $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

# archiver flags and arguments

AR_ARGS = -nologo

# linker flags and arguments

LD_F_NOLOGO = -nologo

LD_ARGS_DLL_T =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_MT_T =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_T =  $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_UX_DEBUG = libWinSysLog.$(COMP_TAG).debug.lib unixem.1.$(COMP_TAG).debug.lib -debug $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

############################################################################
# targets

########################################
# libraries

# core
LIB_CORE_DLL_T			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).dll.test.lib
TARGET_LIB_DLL_T		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).dll.test.lib
LIB_CORE_MT_T			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).mt.test.lib
TARGET_LIB_MT_T		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.test.lib
LIB_CORE_ST_T			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).test.lib
TARGET_LIB_ST_T		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).test.lib
LIB_CORE_ST_UX_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).core.$(COMP_ARCH_OS_TAG).unix.debug.lib
TARGET_LIB_ST_UX_DEBUG		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).unix.debug.lib
TARGET_PDB_ST_UX_DEBUG		=	$(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).unix.debug.pdb

# xtests
LIB_XTESTS_DLL_T		=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).b64.$(COMP_ARCH_OS_TAG).dll.test.lib
LIB_XTESTS_MT_T		=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).b64.$(COMP_ARCH_OS_TAG).mt.test.lib
LIB_XTESTS_ST_T		=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).b64.$(COMP_ARCH_OS_TAG).test.lib
LIB_XTESTS_ST_UX_DEBUG		=	$(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).b64.$(COMP_ARCH_OS_TAG).unix.debug.lib

########################################
# examples



########################################
# tests


##############################
# component tests


##############################
# scratch tests



##############################
# unit tests

TARG_TEST_UNIT_C_1_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).dll.test.exe
TARG_TEST_UNIT_CPP_1_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).dll.test.exe
TARG_TEST_UNIT_C_1_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).mt.test.exe
TARG_TEST_UNIT_CPP_1_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).mt.test.exe
TARG_TEST_UNIT_C_1_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).test.exe
TARG_TEST_UNIT_CPP_1_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).test.exe
TARG_TEST_UNIT_C_1_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.c.1.$(COMP_TAG).unix.debug.exe
TARG_TEST_UNIT_CPP_1_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.cpp.1.$(COMP_TAG).unix.debug.exe

TARGETS_TESTS =\
 $(TARG_TEST_UNIT_C_1_DLL_T)\
 $(TARG_TEST_UNIT_C_1_MT_T)\
 $(TARG_TEST_UNIT_C_1_ST_T)\
 $(TARG_TEST_UNIT_C_1_ST_UX_DEBUG)\
 $(TARG_TEST_UNIT_CPP_1_DLL_T)\
 $(TARG_TEST_UNIT_CPP_1_MT_T)\
 $(TARG_TEST_UNIT_CPP_1_ST_T)\
 $(TARG_TEST_UNIT_CPP_1_ST_UX_DEBUG)\
 \

########################################
# TARGETS_EXAMPLE

TARG_EX_C_1_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).dll.test.exe
TARG_EX_C_2_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).dll.test.exe
TARG_EX_CPP_1_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).dll.test.exe
TARG_EX_CPP_2_DLL_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).dll.test.exe
TARG_EX_C_1_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).mt.test.exe
TARG_EX_C_2_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).mt.test.exe
TARG_EX_CPP_1_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).mt.test.exe
TARG_EX_CPP_2_MT_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).mt.test.exe
TARG_EX_C_1_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).test.exe
TARG_EX_C_2_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).test.exe
TARG_EX_CPP_1_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).test.exe
TARG_EX_CPP_2_ST_T = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).test.exe
TARG_EX_C_1_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.1.$(COMP_TAG).unix.debug.exe
TARG_EX_C_2_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.c.2.$(COMP_TAG).unix.debug.exe
TARG_EX_CPP_1_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.1.$(COMP_TAG).unix.debug.exe
TARG_EX_CPP_2_ST_UX_DEBUG = $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example.cpp.2.$(COMP_TAG).unix.debug.exe

TARGETS_EXAMPLE =\
 $(TARG_EX_C_1_DLL_T)\
 $(TARG_EX_C_2_DLL_T)\
 $(TARG_EX_C_1_MT_T)\
 $(TARG_EX_C_2_MT_T)\
 $(TARG_EX_C_1_ST_T)\
 $(TARG_EX_C_2_ST_T)\
 $(TARG_EX_C_1_ST_UX_DEBUG)\
 $(TARG_EX_C_2_ST_UX_DEBUG)\
 $(TARG_EX_CPP_1_DLL_T)\
 $(TARG_EX_CPP_2_DLL_T)\
 $(TARG_EX_CPP_1_MT_T)\
 $(TARG_EX_CPP_2_MT_T)\
 $(TARG_EX_CPP_1_ST_T)\
 $(TARG_EX_CPP_2_ST_T)\
 $(TARG_EX_CPP_1_ST_UX_DEBUG)\
 $(TARG_EX_CPP_2_ST_UX_DEBUG)\
 \

########################################
# targets

TARGETS_LIB_CORE = \
 $(TARGET_LIB_DLL_T)\
 $(LIB_CORE_DLL_T)\
 $(TARGET_LIB_MT_T)\
 $(LIB_CORE_MT_T)\
 $(TARGET_LIB_ST_T)\
 $(LIB_CORE_ST_T)\
 $(TARGET_LIB_ST_UX_DEBUG)\
 $(LIB_CORE_ST_UX_DEBUG)\
 $(TARGET_PDB_ST_UX_DEBUG)\
 \

TARGETS_LIB_XTESTS = \
 $(LIB_XTESTS_DLL_T)\
 $(LIB_XTESTS_MT_T)\
 $(LIB_XTESTS_ST_T)\
 $(LIB_XTESTS_ST_UX_DEBUG)\
 \

########################################
# OBJS_CORE

OBJ_CORE_b64__DLL_T = $(PROJ_OBJ_DIR)\b64.dll.test.obj

OBJS_CORE_DLL_T = \
 $(OBJ_CORE_b64__DLL_T)\
 \


OBJ_CORE_b64__MT_T = $(PROJ_OBJ_DIR)\b64.mt.test.obj

OBJS_CORE_MT_T = \
 $(OBJ_CORE_b64__MT_T)\
 \


OBJ_CORE_b64__ST_T = $(PROJ_OBJ_DIR)\b64.test.obj

OBJS_CORE_ST_T = \
 $(OBJ_CORE_b64__ST_T)\
 \


OBJ_CORE_b64__ST_UX_DEBUG = $(PROJ_OBJ_DIR)\b64.unix.debug.obj

OBJS_CORE_ST_UX_DEBUG = \
 $(OBJ_CORE_b64__ST_UX_DEBUG)\
 \


OBJS_CORE =\
 $(OBJS_CORE_DLL_T)\
 $(OBJS_CORE_MT_T)\
 $(OBJS_CORE_ST_T)\
 $(OBJS_CORE_ST_UX_DEBUG)\
 \

# xtests

OBJ_xts_core_DLL_T           = $(PROJ_OBJ_DIR)\xtests.b64.core.api.dll.test.obj

OBJ_XTESTS_DLL_T = \
 $(OBJ_xts_core_DLL_T)\
 \

OBJ_xts_core_MT_T           = $(PROJ_OBJ_DIR)\xtests.b64.core.api.mt.test.obj

OBJ_XTESTS_MT_T = \
 $(OBJ_xts_core_MT_T)\
 \

OBJ_xts_core_ST_T           = $(PROJ_OBJ_DIR)\xtests.b64.core.api.test.obj

OBJ_XTESTS_ST_T = \
 $(OBJ_xts_core_ST_T)\
 \

OBJ_xts_core_ST_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.b64.core.api.unix.debug.obj
PDB_xts_core_ST_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.b64.core.api.unix.debug.pdb

OBJ_XTESTS_ST_UX_DEBUG = \
 $(OBJ_xts_core_ST_UX_DEBUG)\
 \

PDB_CORE_ST_UX_DEBUG = \
 $(PDB_xts_core_ST_UX_DEBUG)\
 \


########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_UNIT_C_1_DLL_T = $(PROJ_OBJ_DIR)\test.c.1.dll.test.obj
OBJ_TEST_UNIT_CPP_1_DLL_T = $(PROJ_OBJ_DIR)\test.cpp.1.dll.test.obj
OBJ_TEST_UNIT_C_1_MT_T = $(PROJ_OBJ_DIR)\test.c.1.mt.test.obj
OBJ_TEST_UNIT_CPP_1_MT_T = $(PROJ_OBJ_DIR)\test.cpp.1.mt.test.obj
OBJ_TEST_UNIT_C_1_ST_T = $(PROJ_OBJ_DIR)\test.c.1.test.obj
OBJ_TEST_UNIT_CPP_1_ST_T = $(PROJ_OBJ_DIR)\test.cpp.1.test.obj
OBJ_TEST_UNIT_C_1_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\test.c.1.unix.debug.obj
OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\test.cpp.1.unix.debug.obj

OBJS_TESTS =\
 $(OBJ_TEST_UNIT_C_1_DLL_T)\
 $(OBJ_TEST_UNIT_C_1_MT_T)\
 $(OBJ_TEST_UNIT_C_1_ST_T)\
 $(OBJ_TEST_UNIT_C_1_ST_UX_DEBUG)\
 $(OBJ_TEST_UNIT_CPP_1_DLL_T)\
 $(OBJ_TEST_UNIT_CPP_1_MT_T)\
 $(OBJ_TEST_UNIT_CPP_1_ST_T)\
 $(OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EX_C_1_DLL_T = $(PROJ_OBJ_DIR)\example.c.1.dll.test.obj
OBJ_EX_C_2_DLL_T = $(PROJ_OBJ_DIR)\example.c.2.dll.test.obj
OBJ_EX_CPP_1_DLL_T = $(PROJ_OBJ_DIR)\example.cpp.1.dll.test.obj
OBJ_EX_CPP_2_DLL_T = $(PROJ_OBJ_DIR)\example.cpp.2.dll.test.obj
OBJ_EX_C_1_MT_T = $(PROJ_OBJ_DIR)\example.c.1.mt.test.obj
OBJ_EX_C_2_MT_T = $(PROJ_OBJ_DIR)\example.c.2.mt.test.obj
OBJ_EX_CPP_1_MT_T = $(PROJ_OBJ_DIR)\example.cpp.1.mt.test.obj
OBJ_EX_CPP_2_MT_T = $(PROJ_OBJ_DIR)\example.cpp.2.mt.test.obj
OBJ_EX_C_1_ST_T = $(PROJ_OBJ_DIR)\example.c.1.test.obj
OBJ_EX_C_2_ST_T = $(PROJ_OBJ_DIR)\example.c.2.test.obj
OBJ_EX_CPP_1_ST_T = $(PROJ_OBJ_DIR)\example.cpp.1.test.obj
OBJ_EX_CPP_2_ST_T = $(PROJ_OBJ_DIR)\example.cpp.2.test.obj
OBJ_EX_C_1_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\example.c.1.unix.debug.obj
OBJ_EX_C_2_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\example.c.2.unix.debug.obj
OBJ_EX_CPP_1_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\example.cpp.1.unix.debug.obj
OBJ_EX_CPP_2_ST_UX_DEBUG = $(PROJ_OBJ_DIR)\example.cpp.2.unix.debug.obj

OBJS_EXAMPLES =\
 $(OBJ_EX_C_1_DLL_T)\
 $(OBJ_EX_C_2_DLL_T)\
 $(OBJ_EX_C_1_MT_T)\
 $(OBJ_EX_C_2_MT_T)\
 $(OBJ_EX_C_1_ST_T)\
 $(OBJ_EX_C_2_ST_T)\
 $(OBJ_EX_C_1_ST_UX_DEBUG)\
 $(OBJ_EX_C_2_ST_UX_DEBUG)\
 $(OBJ_EX_CPP_1_DLL_T)\
 $(OBJ_EX_CPP_2_DLL_T)\
 $(OBJ_EX_CPP_1_MT_T)\
 $(OBJ_EX_CPP_2_MT_T)\
 $(OBJ_EX_CPP_1_ST_T)\
 $(OBJ_EX_CPP_2_ST_T)\
 $(OBJ_EX_CPP_1_ST_UX_DEBUG)\
 $(OBJ_EX_CPP_2_ST_UX_DEBUG)\
 \


########################################
# OBJS

OBJS = \
 $(OBJS_LIBS)\
 $(OBJS_TESTS)\
 $(OBJS_EXAMPLES)\
 \

########################################
# SRC_CORE

LIB_CORE_b64_H = $(PROJ_INCLUDE_DIR)\b64\b64.h
LIB_CORE_implicit_link_H = $(PROJ_INCLUDE_DIR)\b64\implicit_link.h

LIB_CORE_b64_C = $(PROJ_SRC_DIR)\b64.c

########################################
# SRC_HEADERS

HEADERS_LIB	= \
 $(LIB_CORE_b64_H)\
 $(LIB_CORE_implicit_link_H)\
 \

HEADERS_MAPPING_CPP =\
 $(PROJ_INCLUDE_DIR)\b64\b64.hpp\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 = $(PROJ_TEST_UNIT_DIR)\test.unit.c.1\test.unit.c.1.c
SRC_TEST_CPP_1 = $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.1\test.unit.cpp.1.cpp

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 = $(PROJ_EXAMPLES_DIR)\c\example.c.1\example.c.1.c
SRC_EXAMPLE_C_2 = $(PROJ_EXAMPLES_DIR)\c\example.c.2\example.c.2.c
SRC_EXAMPLE_CPP_1 = $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.1\example.cpp.1.cpp
SRC_EXAMPLE_CPP_2 = $(PROJ_EXAMPLES_DIR)\cpp\example.cpp.2\example.cpp.2.cpp

############################################################################
# external targets (invokable by make)

# primary

_default:					build

usage:
	@echo "make [build | clean | compile | test | usage] - default is 'build'"

# infrastructure

check.lib.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:				$(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)

# compile targets

compile.libs.core:			$(PROJ_MAKEFILE_NAME)	$(OBJS_CORE)

compile.libs:										compile.libs.core

compile.libs.shwild:		$(PROJ_MAKEFILE_NAME)	$(OBJS_SHWILD)

compile.libs.3pty:									compile.libs.shwild

compile.libs.all:                                   compile.libs compile.libs.3pty

compile.examples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_EXAMPLE)

compile.samples:			$(PROJ_MAKEFILE_NAME)	$(OBJS_SAMPLE)

compile.test.component:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_COMPONENT)

compile.test.scratch:		$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_SCRATCH)

compile.test.unit:			$(PROJ_MAKEFILE_NAME)	$(OBJS_TEST_UNIT)

compile.test:	\
 compile.test.unit\
 compile.test.component\
 compile.test.scratch\
 \

compile:	\
 compile.libs\
 compile.libs.3pty\
 compile.test\
 compile.examples\
 compile.samples\
 \

compile.all:										compile




# build targets

build.libs.core:			check.lib.dir			$(TARGETS_LIB_CORE)

build.libs:											build.libs.core

build.libs.xtests:			check.lib.dir			$(TARGETS_LIB_XTESTS)

build.libs.3pty: \
 build.libs.xtests\
 \

build.libs.all:										build.libs build.libs.3pty

build.examples:				check.bin.dir			$(TARGETS_EXAMPLE)

build.samples:				check.bin.dir			$(TARGETS_SAMPLE)

build.test.component:		check.bin.dir			$(TARGETS_TEST_COMPONENT)

build.test.scratch:			check.bin.dir			$(TARGETS_TEST_SCRATCH)

build.test.unit:			check.bin.dir			$(TARGETS_TEST_UNIT)

build.test:	\
 build.test.unit\
 build.test.component\
 build.test.scratch\
 \

build: \
 build.libs\
 build.test\
 build.examples\
 build.samples\
 \

build.all:											build



# test targets

test.component_:
	@echo Running Test:Component programs ...

test.scratch_:
	@echo Running Test:Scratch programs ...

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_C_1_DLL_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_C_1_MT_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_C_1_ST_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_C_1_ST_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_CPP_1_DLL_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_CPP_1_MT_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_CPP_1_ST_T) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_CPP_1_ST_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)

test.component:			$(PROJ_MAKEFILE_NAME)	build.test.component test.component_

test.scratch:			$(PROJ_MAKEFILE_NAME)	build.test.scratch test.scratch_

test.unit:				$(PROJ_MAKEFILE_NAME)	build.test.unit test.unit_

test:											test.unit test.component

test.all:										test test.scratch
test-all:				test.all


# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-$(RM) $(TARGET_LIB_DLL_T)
	@-$(RM) $(LIB_CORE_DLL_T)
	@-$(RM) $(TARGET_LIB_MT_T)
	@-$(RM) $(LIB_CORE_MT_T)
	@-$(RM) $(TARGET_LIB_ST_T)
	@-$(RM) $(LIB_CORE_ST_T)
	@-$(RM) $(TARGET_LIB_ST_UX_DEBUG)
	@-$(RM) $(LIB_CORE_ST_UX_DEBUG)
	@-$(RM) $(OBJ_CORE_b64__DLL_T)
	@-$(RM) $(OBJ_CORE_b64__MT_T)
	@-$(RM) $(OBJ_CORE_b64__ST_T)
	@-$(RM) $(OBJ_CORE_b64__ST_UX_DEBUG)

clean.libs.xtests:		makefile

clean.libs:	clean.libs.core\
 clean.libs.xtests\
 \

clean.test:
	@-$(RM) $(TARG_TEST_UNIT_C_1_DLL_T)
	@-$(RM) $(TARG_TEST_UNIT_C_1_MT_T)
	@-$(RM) $(TARG_TEST_UNIT_C_1_ST_T)
	@-$(RM) $(TARG_TEST_UNIT_C_1_ST_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_CPP_1_DLL_T)
	@-$(RM) $(TARG_TEST_UNIT_CPP_1_MT_T)
	@-$(RM) $(TARG_TEST_UNIT_CPP_1_ST_T)
	@-$(RM) $(TARG_TEST_UNIT_CPP_1_ST_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_C_1_DLL_T)
	@-$(RM) $(OBJ_TEST_UNIT_C_1_MT_T)
	@-$(RM) $(OBJ_TEST_UNIT_C_1_ST_T)
	@-$(RM) $(OBJ_TEST_UNIT_C_1_ST_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_CPP_1_DLL_T)
	@-$(RM) $(OBJ_TEST_UNIT_CPP_1_MT_T)
	@-$(RM) $(OBJ_TEST_UNIT_CPP_1_ST_T)
	@-$(RM) $(OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG)

clean.examples:
	@-$(RM) $(TARG_EX_C_1_DLL_T)
	@-$(RM) $(TARG_EX_C_2_DLL_T)
	@-$(RM) $(TARG_EX_C_1_MT_T)
	@-$(RM) $(TARG_EX_C_2_MT_T)
	@-$(RM) $(TARG_EX_C_1_ST_T)
	@-$(RM) $(TARG_EX_C_2_ST_T)
	@-$(RM) $(TARG_EX_C_1_ST_UX_DEBUG)
	@-$(RM) $(TARG_EX_C_2_ST_UX_DEBUG)
	@-$(RM) $(TARG_EX_CPP_1_DLL_T)
	@-$(RM) $(TARG_EX_CPP_2_DLL_T)
	@-$(RM) $(TARG_EX_CPP_1_MT_T)
	@-$(RM) $(TARG_EX_CPP_2_MT_T)
	@-$(RM) $(TARG_EX_CPP_1_ST_T)
	@-$(RM) $(TARG_EX_CPP_2_ST_T)
	@-$(RM) $(TARG_EX_CPP_1_ST_UX_DEBUG)
	@-$(RM) $(TARG_EX_CPP_2_ST_UX_DEBUG)
	@-$(RM) $(OBJ_EX_C_1_DLL_T)
	@-$(RM) $(OBJ_EX_C_2_DLL_T)
	@-$(RM) $(OBJ_EX_C_1_MT_T)
	@-$(RM) $(OBJ_EX_C_2_MT_T)
	@-$(RM) $(OBJ_EX_C_1_ST_T)
	@-$(RM) $(OBJ_EX_C_2_ST_T)
	@-$(RM) $(OBJ_EX_C_1_ST_UX_DEBUG)
	@-$(RM) $(OBJ_EX_C_2_ST_UX_DEBUG)
	@-$(RM) $(OBJ_EX_CPP_1_DLL_T)
	@-$(RM) $(OBJ_EX_CPP_2_DLL_T)
	@-$(RM) $(OBJ_EX_CPP_1_MT_T)
	@-$(RM) $(OBJ_EX_CPP_2_MT_T)
	@-$(RM) $(OBJ_EX_CPP_1_ST_T)
	@-$(RM) $(OBJ_EX_CPP_2_ST_T)
	@-$(RM) $(OBJ_EX_CPP_1_ST_UX_DEBUG)
	@-$(RM) $(OBJ_EX_CPP_2_ST_UX_DEBUG)

clean: clean.libs clean.test clean.examples

############################################################################
# build targets

##################################################
# libraries

########################################
# Main library - 'b64.X.core.a'


$(TARGET_LIB_DLL_T):	$(LIB_CORE_DLL_T)
	@$(CP) $(LIB_CORE_DLL_T) $@

$(LIB_CORE_DLL_T): $(OBJS_CORE_DLL_T) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_DLL_T)

$(OBJ_CORE_b64__DLL_T): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_T) -Fo$@ $(PROJ_SRC_DIR)\b64.c


$(TARGET_LIB_MT_T):	$(LIB_CORE_MT_T)
	@$(CP) $(LIB_CORE_MT_T) $@

$(LIB_CORE_MT_T): $(OBJS_CORE_MT_T) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_MT_T)

$(OBJ_CORE_b64__MT_T): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_T) -Fo$@ $(PROJ_SRC_DIR)\b64.c


$(TARGET_LIB_ST_T):	$(LIB_CORE_ST_T)
	@$(CP) $(LIB_CORE_ST_T) $@

$(LIB_CORE_ST_T): $(OBJS_CORE_ST_T) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_ST_T)

$(OBJ_CORE_b64__ST_T): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_T) -Fo$@ $(PROJ_SRC_DIR)\b64.c

$(TARGET_PDB_ST_UX_DEBUG):	$(TARGET_LIB_ST_UX_DEBUG)

$(TARGET_LIB_ST_UX_DEBUG):	$(LIB_CORE_ST_UX_DEBUG)
	@$(CP) $(LIB_CORE_ST_UX_DEBUG) $@

$(LIB_CORE_ST_UX_DEBUG): $(OBJS_CORE_ST_UX_DEBUG) makefile
	$(AR) $(AR_ARGS) -out:$@ $(OBJS_CORE_ST_UX_DEBUG)

$(OBJ_CORE_b64__ST_UX_DEBUG): $(PROJ_SRC_DIR)\b64.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\b64.c

########################################
# xTests library - 'xtests.V.XXXX.core.a'

$(LIB_XTESTS_DLL_T): $(OBJ_XTESTS_DLL_T) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_T)

$(OBJ_xts_core_DLL_T): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_T) $(CPPC_XTESTS_INCLUDES_DLL_T) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_T): $(OBJ_XTESTS_MT_T) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_T)

$(OBJ_xts_core_MT_T): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_T) $(CPPC_XTESTS_INCLUDES_MT_T) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_ST_T): $(OBJ_XTESTS_ST_T) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_ST_T)

$(OBJ_xts_core_ST_T): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_T) $(CPPC_XTESTS_INCLUDES_ST_T) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_ST_UX_DEBUG): $(OBJ_XTESTS_ST_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_ST_UX_DEBUG)

$(OBJ_xts_core_ST_UX_DEBUG): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_UX_DEBUG) $(CPPC_XTESTS_INCLUDES_ST_UX_DEBUG) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

##################################################
# examples

# C example client

$(TARG_EX_C_1_DLL_T):	\
	$(OBJ_EX_C_1_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_EX_C_1_DLL_T) $(TARGET_LIB_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_EX_C_1_DLL_T):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_T) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARG_EX_C_2_DLL_T):	\
	$(OBJ_EX_C_2_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_EX_C_2_DLL_T) $(TARGET_LIB_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_EX_C_2_DLL_T):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_T) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARG_EX_C_1_MT_T):	\
	$(OBJ_EX_C_1_MT_T)\
	$(TARGET_LIB_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_EX_C_1_MT_T) $(TARGET_LIB_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_EX_C_1_MT_T):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_T) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARG_EX_C_2_MT_T):	\
	$(OBJ_EX_C_2_MT_T)\
	$(TARGET_LIB_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_EX_C_2_MT_T) $(TARGET_LIB_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_EX_C_2_MT_T):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_T) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARG_EX_C_1_ST_T):	\
	$(OBJ_EX_C_1_ST_T)\
	$(TARGET_LIB_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_EX_C_1_ST_T) $(TARGET_LIB_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_EX_C_1_ST_T):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_T) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARG_EX_C_2_ST_T):	\
	$(OBJ_EX_C_2_ST_T)\
	$(TARGET_LIB_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_EX_C_2_ST_T) $(TARGET_LIB_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_EX_C_2_ST_T):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_T) -Fo$@ $(SRC_EXAMPLE_C_2)

$(TARG_EX_C_1_ST_UX_DEBUG):	\
	$(OBJ_EX_C_1_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_EX_C_1_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_EX_C_1_ST_UX_DEBUG):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_EXAMPLE_C_1)

$(TARG_EX_C_2_ST_UX_DEBUG):	\
	$(OBJ_EX_C_2_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_EX_C_2_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_EX_C_2_ST_UX_DEBUG):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_EXAMPLE_C_2)

# C++ example client

$(TARG_EX_CPP_1_DLL_T):	\
	$(OBJ_EX_CPP_1_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_EX_CPP_1_DLL_T) $(TARGET_LIB_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_EX_CPP_1_DLL_T):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_T) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARG_EX_CPP_2_DLL_T):	\
	$(OBJ_EX_CPP_2_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_EX_CPP_2_DLL_T) $(TARGET_LIB_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_EX_CPP_2_DLL_T):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_T) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARG_EX_CPP_1_MT_T):	\
	$(OBJ_EX_CPP_1_MT_T)\
	$(TARGET_LIB_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_EX_CPP_1_MT_T) $(TARGET_LIB_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_EX_CPP_1_MT_T):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_T) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARG_EX_CPP_2_MT_T):	\
	$(OBJ_EX_CPP_2_MT_T)\
	$(TARGET_LIB_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_EX_CPP_2_MT_T) $(TARGET_LIB_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_EX_CPP_2_MT_T):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_T) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARG_EX_CPP_1_ST_T):	\
	$(OBJ_EX_CPP_1_ST_T)\
	$(TARGET_LIB_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_EX_CPP_1_ST_T) $(TARGET_LIB_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_EX_CPP_1_ST_T):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_T) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARG_EX_CPP_2_ST_T):	\
	$(OBJ_EX_CPP_2_ST_T)\
	$(TARGET_LIB_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_EX_CPP_2_ST_T) $(TARGET_LIB_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_EX_CPP_2_ST_T):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_T) -Fo$@ $(SRC_EXAMPLE_CPP_2)

$(TARG_EX_CPP_1_ST_UX_DEBUG):	\
	$(OBJ_EX_CPP_1_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_EX_CPP_1_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_EX_CPP_1_ST_UX_DEBUG):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_EXAMPLE_CPP_1)

$(TARG_EX_CPP_2_ST_UX_DEBUG):	\
	$(OBJ_EX_CPP_2_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_EX_CPP_2_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_EX_CPP_2_ST_UX_DEBUG):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_EXAMPLE_CPP_2)






##################################################
# tests

##############################
# component tests

##############################
# scratch tests

##############################
# unit tests

# C test client

$(TARG_TEST_UNIT_C_1_DLL_T):	\
	$(OBJ_TEST_UNIT_C_1_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	$(LIB_XTESTS_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_TEST_UNIT_C_1_DLL_T) $(TARGET_LIB_DLL_T) $(LIB_XTESTS_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_TEST_UNIT_C_1_DLL_T):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DLL_T) -Fo$@ $(SRC_TEST_C_1)

$(TARG_TEST_UNIT_C_1_MT_T):	\
	$(OBJ_TEST_UNIT_C_1_MT_T)\
	$(TARGET_LIB_MT_T)\
	$(LIB_XTESTS_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_TEST_UNIT_C_1_MT_T) $(TARGET_LIB_MT_T) $(LIB_XTESTS_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_TEST_UNIT_C_1_MT_T):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_MT_T) -Fo$@ $(SRC_TEST_C_1)

$(TARG_TEST_UNIT_C_1_ST_T):	\
	$(OBJ_TEST_UNIT_C_1_ST_T)\
	$(TARGET_LIB_ST_T)\
	$(LIB_XTESTS_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_TEST_UNIT_C_1_ST_T) $(TARGET_LIB_ST_T) $(LIB_XTESTS_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_TEST_UNIT_C_1_ST_T):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_T) -Fo$@ $(SRC_TEST_C_1)

$(TARG_TEST_UNIT_C_1_ST_UX_DEBUG):	\
	$(OBJ_TEST_UNIT_C_1_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	$(LIB_XTESTS_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_TEST_UNIT_C_1_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(LIB_XTESTS_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_TEST_UNIT_C_1_ST_UX_DEBUG):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_TEST_C_1)

# C++ test client

$(TARG_TEST_UNIT_CPP_1_DLL_T):	\
	$(OBJ_TEST_UNIT_CPP_1_DLL_T)\
	$(TARGET_LIB_DLL_T)\
	$(LIB_XTESTS_DLL_T)\
	makefile
	$(LD) $(LD_ARGS_DLL_T) -out:$@ $(OBJ_TEST_UNIT_CPP_1_DLL_T) $(TARGET_LIB_DLL_T) $(LIB_XTESTS_DLL_T) $(3PTY_LIBS__DLL_T)

$(OBJ_TEST_UNIT_CPP_1_DLL_T):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_T) -Fo$@ $(SRC_TEST_CPP_1)

$(TARG_TEST_UNIT_CPP_1_MT_T):	\
	$(OBJ_TEST_UNIT_CPP_1_MT_T)\
	$(TARGET_LIB_MT_T)\
	$(LIB_XTESTS_MT_T)\
	makefile
	$(LD) $(LD_ARGS_MT_T) -out:$@ $(OBJ_TEST_UNIT_CPP_1_MT_T) $(TARGET_LIB_MT_T) $(LIB_XTESTS_MT_T) $(3PTY_LIBS__MT_T)

$(OBJ_TEST_UNIT_CPP_1_MT_T):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_T) -Fo$@ $(SRC_TEST_CPP_1)

$(TARG_TEST_UNIT_CPP_1_ST_T):	\
	$(OBJ_TEST_UNIT_CPP_1_ST_T)\
	$(TARGET_LIB_ST_T)\
	$(LIB_XTESTS_ST_T)\
	makefile
	$(LD) $(LD_ARGS_ST_T) -out:$@ $(OBJ_TEST_UNIT_CPP_1_ST_T) $(TARGET_LIB_ST_T) $(LIB_XTESTS_ST_T) $(3PTY_LIBS__ST_T)

$(OBJ_TEST_UNIT_CPP_1_ST_T):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_T) -Fo$@ $(SRC_TEST_CPP_1)

$(TARG_TEST_UNIT_CPP_1_ST_UX_DEBUG):	\
	$(OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG)\
	$(TARGET_LIB_ST_UX_DEBUG)\
	$(LIB_XTESTS_ST_UX_DEBUG)\
	makefile
	$(LD) $(LD_ARGS_ST_UX_DEBUG) -out:$@ $(OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG) $(TARGET_LIB_ST_UX_DEBUG) $(LIB_XTESTS_ST_UX_DEBUG) $(3PTY_LIBS__ST_UX_DEBUG)

$(OBJ_TEST_UNIT_CPP_1_ST_UX_DEBUG):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_UX_DEBUG) -Fo$@ $(SRC_TEST_CPP_1)

############################################################################
