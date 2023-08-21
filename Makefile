# LBM Makefile

TARGET= LBExC
CXX= mpiCC
CXXFLAGS= -Wall -O3 -fopenmp -march=native
SRCDIR= ./src
OBJDIR= ./obj
RESTART= ./restart
SOURCE= $(wildcard $(SRCDIR)/*.cpp)
OBJECT= $(addprefix $(OBJDIR)/, $(notdir $(SOURCE:.cpp=.o)))
OUTPUT= out.$(TARGET).txt field*.vtr output0* rst stt output0*.vtm geometryflag.vtm geometryflag output stop
STOP= stop

$(TARGET): $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECT) -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $< 

MAKE_JOBS_SAFE=yes

.PHONY: clean
clean: 
# rm -rf $(OBJECT) $(OUTPUT) $(OBJDIR) $(RESTART) $(TARGET)
	rm -rf $(OUTPUT) $(RESTART) $(TARGET)
allclean: 
	rm -rf $(OBJECT) $(OUTPUT) $(OBJDIR) $(RESTART) $(TARGET)
run:
	make clean
	make -j6
	sh run.sh
continue:
	rm -rf $(STOP)
	sh run.sh

test:
	make allclean
	make -j6
	sh run.sh