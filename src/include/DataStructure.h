#ifndef DS_H
#define DS_H
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

template < class Data > class edge_ {
  private:
    Data vertex;
    int weight;
  public:
    edge_(Data v, int w) {
	setVertex(v);
	setWeight(w);
    };
    Data getVertex() const {
	return vertex;
    };
    void setVertex(Data v) {
	vertex = v;
    };
    int getWeight() {
	return weight;
    };
    void setWeight(int w) {
	weight = w;
    };

    bool operator==(const edge_ < Data > &other) const {
	return (other.getVertex() == this->vertex);
    }
};

template < class Data > class vertex_ {
  private:
    Data value;
    string color;
    int distance;
    Data father;
    int key;
    int input;
    int output;
  public:
    vertex_() {
	setValue("NULL");
    };
    vertex_(Data v) {
	setValue(v);
    };
    Data getValue() const {
	return value;
    };
    void setValue(Data v) {
	value = v;
    };
    bool operator==(const vertex_ < Data > &other) const {
	return (other.getValue() == this->value);
    };


    void setColor(string color) {
	this->color = color;
    };
    string getColor() {
	return color;
    };
    void setDistance(int distance) {
	this->distance = distance;
    };
    int getDistance() {
	return distance;
    };
    void setFather(Data father) {
	this->father = father;
    };
    Data getFather() {
	return father;
    };
    void setKey(int key) {
	this->key = key;
    };
    int getKey() const {
	return key;
    };

    bool operator<(const vertex_ < Data > &other) const {
	return (other.getKey() < this->key);
    };

    void setOutput(int output) {
	this->output = output;
    };
    int getOutput() const {
	return output;
    };

    void setInput(int input) {
	this->input = input;
    };
    int getInput() {
	return input;
    };
};

template < class Data > class DataStructure {
  public:
    virtual void addVertex(Data) {
    };
    virtual void addEdge(Data, Data, int) {
    };
    virtual void removeEdge(Data, Data) {
    };
    virtual list < edge_ < Data >> getEdges(vertex_ < Data >) {
    };
    virtual list < vertex_ < Data > *>getVertexs() {
    };
    virtual vertex_ < Data > *getVertex(Data) {
    };
};

#endif
