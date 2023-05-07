# Syntax for a "rule" (use tabs, not spaces): 
#
# target: dependency1, dependency2,...
#		command
#		command
#
# Note: the first target is the default target
files := main.cpp ./model/Server.cpp ./view/Window.cpp ./controller/Controller.cpp \
./model/Food.cpp ./model/User.cpp
dontojo:
	echo "Compiling..."
	g++ -std=c++14 $(files) -o program.exe
	./program.exe

hello:
	echo "Hello world"