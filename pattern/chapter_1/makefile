export BUILD_VER := DEBUG
export CXXFLAGS := -std=c++11 -Wall
export RM := rm -f

vpath %.cpp ./
vpath %.h ./

.PHONY:all clean
all : 

CXXINCLUDES = -I ./
SRCS_WITH_PATH = $(wildcard ./*.cpp)
SRCS = $(SRCS_WITH_PATH:./%.cpp=%.cpp)
OBJS = $(SRCS:.cpp=.o)
OBJS_WITH_PATH = $(SRCS:%.cpp=./compile/%.o)

TARGET_NAME := Calculator
OUTDIR := ../debug/

ifeq ($(BUILD_VER), DEBUG)
CXXFLAGS += -g3
endif

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(CXXINCLUDES) -c $< -o ./compile/$@

all:$(TARGET_NAME)

$(TARGET_NAME):$(OBJS)
	$(CXX) -o $(OUTDIR)$(TARGET_NAME) $(OBJS_WITH_PATH)

clean:
	$(RM) $(OUTDIR)$(TARGET_NAME) $(OBJS_WITH_PATH)