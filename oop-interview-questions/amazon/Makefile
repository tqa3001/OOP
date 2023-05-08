define files 
main.cpp ./controller/controller.cpp \
./server/server.cpp \
./server/user.cpp \
./server/cart.cpp \
./server/item.cpp \
./server/payment.cpp
endef 

amazon:
	echo "Compiling..."
	c++ -std=c++14 ${files} -o amazon.exe
	./amazon.exe