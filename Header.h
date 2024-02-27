#include <iostream>
using namespace std;

struct customer {
	int ID;
	string firstName, lastName;

};


struct dress {
	int ID;
	double price;
	string size;
};

//Linked List ADT
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

template <class Type>
class linkedListType
{
protected:
	int count;
	nodeType<Type>* first;
	nodeType<Type>* last;
public:
	const linkedListType<Type>& operator= (const
		linkedListType<Type>&);
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	void insertFirst(const Type& newItem);
	linkedListType();
	linkedListType(const linkedListType<Type>& otherList);
	~linkedListType();
private:
	void copyList(const linkedListType<Type>& otherList);
};


//array list ADT
template <class elemType>
class arrayListType
{
public:
	const arrayListType<elemType>& operator=(const
		arrayListType<elemType>&);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print() const;
	bool isItemAtEqual(int location, const elemType& item) const;
	void insertAt(int location, const elemType& insertItem);
	void insertEnd(const elemType& insertItem);
	void removeAt(int location);
	void retrieveAt(int location, elemType& retItem) const;
	void replaceAt(int location, const elemType& repItem);
	void clearList();
	int seqSearch(const elemType& item) const;
	void insert(const elemType& insertItem);
	void remove(const elemType& removeItem);
	arrayListType(int size = 100);
	arrayListType(const arrayListType<elemType>& otherList);
	~arrayListType();
	void removeAll(const elemType& removeItem);
protected:
	elemType* list;
	int length;
	int maxSize;
};