

allcfile:=$(wildcard *.c)
allcppfile:=$(wildcard *.cpp)
notusedfile:=testall.cpp
usedcppfile:=$(filter-out $(notusedfile),$(allcppfile))
objc=$(patsubst %.c,%.o,$(allcfile))
objcpp=$(patsubst %.cpp,%.o,$(usedcppfile))
target=main

# 自动推到代替main2

all:$(target)
	./$(target)

$(target):$(objcpp) $(objc)
	g++ -o $@ *.o  -lgtest -pthread

#下面这2个也可以不写 利用自动推导
# $(objc):%.o:%.c
# 	gcc -o $@ -c $<
# $(objcpp):%.o:%.cpp
# 	g++ -o $@ -c $<


.PHONY: main2
main2:
	gcc -o cfunc.o -c cfunc.c
	g++ -o src.o -c src.cpp
	g++ -o testsrc.o -c testsrc.cpp
	g++ -o testsrc2.o -c testsrc2.cpp
	g++ -o testcfunc.o -c testcfunc.cpp
	g++ -o testFixtures.o -c testFixtures.cpp
	g++ -o testmain.o -c testmain.cpp
	g++ -o main *.o  -lgtest -pthread

clean:
	rm *.o $(target)


allsrc=$(wildcard *.cpp)
allo=$(subst .cpp,.o,$(allsrc))
allo2=$(patsubst %.cpp,%.o,$(allsrc))

.PHONY: test
test:
# 打印变量的值

	$(info $(CC))
	echo $(CC)
	echo $(CFLAGS)
	echo $(CPPFLAGS)
	echo $(CXXFLAGS)
	$(info $(allsrc))
	$(info $(allo))
	$(info $(allo2))