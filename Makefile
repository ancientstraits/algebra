CFLAGS=-Iinclude
LFLAGS=-lm
OBJS:=$(patsubst src/%.c, obj/%.o, $(wildcard src/*.c))
DEPS=$(wildcard include/*.h)

BUILD_TYPE?=debug

ifeq (BUILD_TYPE,release)
	CFLAGS+=-O2 -NDEBUG
endif
ifeq (BUILD_TYPE,debug)
	CFLAGS+= -g -ggdb
endif

obj/%.o: src/%.c $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LFLAGS)
