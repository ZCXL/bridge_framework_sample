PWD = $(shell pwd)
CXX := g++
LINKER := g++
CXXFLAGS := -pipe -Wall -O2 -g -std=c++11
LIBS :=
INCLUDE :=
LINKFLAGS :=
AR := ar
JAVA_PATH = ${JAVA_HOME}
OBJECTS = javatocxx.o

DEP_INCPATH = -I$(JAVA_PATH)/include/ \
              -I$(JAVA_PATH)/include/linux/ 
DEP_LDFLAGS = -L$(JAVA_PATH)/jre/lib/amd64/server/
DEP_LDLIBS = -ljvm -lbridge -lbridge_object
INCPATH = -I ./
default:javatocxx

javatocxx:$(OBJECTS)
	$(LINKER) $(DEP_LDFLAGS) $(DEP_LDLIBS) $(LINKFLAGS) -o $@ $(OBJECTS)

javatocxx.o:$(CORE_DEPS)\
	javatocxx.cpp
	$(CC) -c $(CXXFLAGS) $(INCPATH) $(DEP_INCPATH) -o $@ javatocxx.cpp
clean:
	rm javatocxx
	rm javatocxx.o
