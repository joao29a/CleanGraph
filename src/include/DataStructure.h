
template<class Data>
class DataStructure{
public: 
	virtual void addEdge(Data,Data) {} 
	virtual void remove(Data,Data) {} 
	virtual bool search(Data,Data) {} 
};
