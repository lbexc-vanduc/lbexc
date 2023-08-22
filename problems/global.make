TARGET 		= LBExC

CXX			= mpiCC

CXXFLAGS	= -Wall -O3 -fopenmp -march=native

#LBEXC_HOME defines the directory in which we will find the LBExC directory
LBEXC_HOME	= ../../lbexc-src

OBJDIR		= ./obj
RESTART		= ./restart

HEADER		:= $(wildcard $(LBEXC_HOME)/*.H)
SOURCE		:= $(wildcard ./*.cpp $(LBEXC_HOME)/*.cpp)

$(TARGET): $(OBJECT)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECT) -lm
	@echo "Linking complete!"

$(OBJDIR)/%.o: $(SOURCE)
	-mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $< 
	@echo "Compiled "$<" successfully!"

hello:
	echo "Hello, World"
	echo $(SOURCE)

allclean: 
	rm -rf $(OBJECT) $(OUTPUT) $(OBJDIR) $(RESTART) $(TARGET)

#Compile codes
compile: 
	make allclean
	make -j6