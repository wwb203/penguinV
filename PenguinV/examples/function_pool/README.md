#How to compile    
- Microsoft Visual Studio    
Open example_function_pool.vcxproj file in this directory to create solution for your Visual Studio version. This project was created under Visual Studio 2015.

- g++    
In this directory you need to type/paste this text in terminal:    
	```bash
	g++ -std=c++11 -pthread -Wall example_function_pool.cpp ../../Library/image_function.cpp ../../Library/thread_pool.cpp ../../Library/function_pool.cpp ../../Library/penguinv/penguinv.cpp -o application
	```

- make    
In this directory you need to type/paste this text in terminal:    
	```bash
	make ./example_function_pool
	```
