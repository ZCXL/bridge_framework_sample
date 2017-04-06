/*************************************************************************
	> File Name: javatocxx.cpp
	> Author: zhuchao
	> Mail: zhuchao1995@hotmail.com 
	> Created Time: Fri 31 Mar 2017 10:47:57 AM UTC
 ************************************************************************/
#include <iostream>
#include "jni_bridge/com/javatocpp/test/Person.h"
#include "jni_bridge/java/lang/String.h"
#include "jni_bridge/java/lang/StringBuilder.h"
#include "jni_bridge/java/util/ArrayList.h"

using namespace java;
int main(int argc, char *argv[]) {
	java::String str(java::bridge_string("zhuchao"));
	std::cout<<str;
	java::bridge_string sub = str.substring(1, 4);
	std::cout<<sub<<std::endl;
	//Get some char
	java::bridge_char c = str.charAt(3);
	std::cout << "charAt:" << char(c) << std::endl;
	//compareTo
	java::bridge_string com("sb");
	if (str.compareTo(com) == 0) {
		std::cout << "Equal" << std::endl;
	} else {
		std::cout << "Not equal" << std::endl;
	}
	if (str.startsWith("zhu") == 0) {
		std::cout << "Start" << std::endl;
	}
	java::bridge_string rep = str.replace('h', 'y');
	std::cout << rep << std::endl;
	std::cout << str.toString() << std::endl;
	java::StringBuilder builder;
	//builder.append(java::bridge_string("hello, "));
	builder.append("hello, ");
	builder.append("world!");
	std::cout << builder.toString() << std::endl;
	std::cout << String::valueOf(100) << std::endl;
	std::cout << Person::get_staticString() << std::endl;
	java::Person person;
	java::Person::InnerClass inner_class(person);
	std::cout << inner_class.getA() << std::endl;
	std::cout << inner_class.getB() << std::endl;
	java::ArrayList list;
	for (int i = 0; i < 10; i++) {
		java::Person tmp;
		list.add(tmp);
	}
	std::cout << list.size() << std::endl;
	return 0;
}
