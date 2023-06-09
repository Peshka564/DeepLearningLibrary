#ifndef SCALAR_ENGINE_HPP
#define SCALAR_ENGINE_HPP

#include <vector>
#include <functional>
#include <iostream>

class Value {
//change back to private
public:
	double data, grad;
	std::vector<Value*> children;
	std::function<void(double, double)> adjustGradients;
private:
	std::vector<const Value*> topoSort() const;
	void buildTopo(std::vector<const Value*>& visited, std::vector<const Value*>& topo) const;
	void backward() const;
public:
	Value();
	Value(double d);
	void backprop();

	double getData() const { return data; }
	double getGrad() const { return grad; }
	
	// to add: other activation functions
	friend Value operator+(Value& one, Value& other);
	friend Value operator*(Value& one, Value& other);
	friend Value operator-(Value& one, Value& other);
	friend Value sigmoid(Value& one);
	friend std::ostream& operator<<(std::ostream&, const Value&);
};

#endif