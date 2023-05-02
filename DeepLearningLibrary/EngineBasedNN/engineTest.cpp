#include <iostream>
#include <vector>
#include "./scalarEngine/engine.hpp"

// topoSort
void topoSort(const Value& root) {
	std::vector<Value&> sorted;
}

int main() {
	Value v(5);
	Value g(10);
	Value p = v + g;
	Value d = v + g;
	Value q = p + d;
	q.grad = 1;
	q.backward();

	std::cout << "q: " << q.data << " " << q.grad << std::endl;
	std::cout << "p: " << p.data << " " << p.grad << std::endl;
	std::cout << "d: " << d.data << " " << d.grad << std::endl;
	std::cout << "v: " << v.data << " " << v.grad << std::endl;
	std::cout << "g: " << g.data << " " << g.grad << std::endl;
}