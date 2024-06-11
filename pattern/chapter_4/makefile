export BUILD_VER := DEBUG
export CXXFLAGS := -std=c++11 -Wall
export RM := rm -f

vpath %.cpp ./src
vpath %.h ./header

.PHONY:all clean clean_cache
all : 

CXXINCLUDES = -I ./header
SRCS_WITH_PATH = $(wildcard ./src/*.cpp)
SRCS = $(SRCS_WITH_PATH:./src/%.cpp=%.cpp)
DEPS = $(SRCS:.cpp=.d)
DEPS_WITH_PATH = $(SRCS:%.cpp=./.d/%.d)
OBJS = $(SRCS:.cpp=.o)
OBJS_WITH_PATH = $(SRCS:%.cpp=./compile/%.o)
TARGET_NAME := Proxy
OUTDIR := ../debug/

ifeq ($(BUILD_VER), DEBUG)
CXXFLAGS += -g3
endif

-include $(DEPS)

%.d:%.cpp
	$(CXX) $(CXXINCLUDES) -MM $< > .d/$@

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) -c $< -o ./compile/$@

all:$(TARGET_NAME)

$(TARGET_NAME):$(OBJS)
	$(CXX) -o $(OUTDIR)$(TARGET_NAME) $(OBJS_WITH_PATH)

clean:
	$(RM) $(OUTDIR)$(TARGET_NAME) $(OBJS_WITH_PATH)

clean_cache:
	$(RM) $(OBJS_WITH_PATH) $(DEPS_WITH_PATH)