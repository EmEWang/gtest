

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

####这部分生成.d文件的操作 本程序暂时没用 大工程可能有用
# 说明
# 在不使用自动生成依赖时：
# 如果是一个大型项目，必须清楚知道每个源文件包含哪些头文件，并且在加入/删除头文件时修改Makefile。
# 编译器的-M/-MM选项
# 作用：自动寻找源文件中包含的头文件，并生成一个依赖关系。
# 在GNU的C/C++编译器中要使用-MM选项，不然会包含一些标准库的头文件。
# 如何将编译器的功能与Makefile联系到一起
# 让Makefile依赖于源文件的方案并不现实。
# GNU建议把编译器为每一个源文件的自动生成的依赖关系放到一个文件中，例如每个.c文件都对应一个.d文件。
# 细节
# 所有 .d 文件都依赖于 .c 文件。
# 先删除所有目标，即.d文件。
# 为每个依赖文件 $<（即.c文件）生成依赖文件，$@表示模式%.d文件，$$$$表示随机编号 $$表示$ $$$$表示$$ 进程id。
# 第三行是一个替换命令，具体查看sed文件本身。正则替换 xx.o : 替换为 xx.o xx.d :
# 第四行是删除临时文件。
# 目标：在编译器生成的依赖关系中加入.d文件的依赖，即把依赖关系 main.o : main.c defs.h 转换为 main.o main.d: main.c defs.h。
# 这样.d文件会自动更新。
# 之后吧这些生成的规则放到Makefile中，通过include命令。要注意顺序，不然可能就会作为make的默认target了。
%.d: %.c
	@set -e; rm -f $@; \
	gcc -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

%.d: %.cpp
	@set -e; rm -f $@; \
	g++ -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$
# 下面是通过include引入.d文件
alldfile = $(patsubst %.c,%.d,$(allcfile)) $(patsubst %.cpp,%.d,$(usedcppfile))
include $(alldfile)
####

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
	-rm $(objcpp) $(objc) $(target) $(alldfile)


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