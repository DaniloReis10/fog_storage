CONTIKI  = ../../..
CFLAGS += -DPROJECT_CONF_H=\"project-conf.h\"

TARGET_LIBFILES = -lm


CONTIKI_PROJECT = ../../..
PROJECT_SOURCEFILES += node.c

include $(CONTIKI)/Makefile.include
