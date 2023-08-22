TARGET= LBExC

CXX= mpiCC

CXXFLAGS= -Wall -O3 -fopenmp -march=native

PRODIR 		= ./problems/tayler-green
SRCDIR		= ./lbexcsrc
OBJDIR 		= $(PRODIR)/obj
RESTART 	= $(PRODIR)/restart

SOURCE		:= $(wildcard $(SRCDIR)/*.cpp $(PRODIR)/*.cpp)
INCLUDES 	:= $(wildcard $(SRCDIR)/*.H $(PRODIR)/*.H)
OBJECT		= $(addprefix $(OBJDIR)/, $(notdir $(SOURCE:.cpp=.o)))
OUTPUT		= $(PRODIR)/out.$(TARGET).txt $(PRODIR)/output
STOP		= $(PRODIR)/stop

	
$(TARGET): $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECT) -lm
	@echo "Linking complete!"

	
$(OBJDIR)/%.o: $(PRODIR)/%.cpp 
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< 
	@echo "Compiled "\"$<\"" successfully!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $< 
	@echo "Compiled "\"$<\"" successfully!"
	

MAKE_JOBS_SAFE=yes

.PHONY: clean
hello:
	echo $(OBJECT)
clean: 
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