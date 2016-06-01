#.SUFFIXES	: .c .cpp .o
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj
LIB_DIR=lib
TEST_DIR=test

#Lib
TIMER_LIB=Timer

#make
all	: libdir timer testpg

libdir	: 
	mkdir -p $(LIB_DIR)
	mkdir -p $(OBJ_DIR)
	
timer	:
	g++ -c $(SRC_DIR)/Timer.cpp -I$(INC_DIR)
	mv Timer.o $(OBJ_DIR)
	ar rv $(LIB_DIR)/lib$(TIMER_LIB).a $(OBJ_DIR)/Timer.o

testpg	:
	g++ -o $(TEST_DIR)/TimerTest $(TEST_DIR)/TimerTest.cpp -I$(INC_DIR) -L$(LIB_DIR) -l$(TIMER_LIB) -lpthread
	g++ -o $(TEST_DIR)/TimerTest2 $(TEST_DIR)/TimerTest2.cpp -I$(INC_DIR) -L$(LIB_DIR) -l$(TIMER_LIB) -lpthread

#.PHONY : clean	
clean	: 
	rm -rf $(OBJ_DIR)/*
	rm -rf $(LIB_DIR)/*