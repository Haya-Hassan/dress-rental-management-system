#include "header.h"

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator= (const
	linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}
	cout << "assign op is called: " << endl;
	return *this;
}
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == NULL);
}
template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type>* current;
	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
}
template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type>* temp;
	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type>* temp;
	temp = new nodeType<Type>;
	temp->info = newItem;
	temp->link = first;
	first = temp;
	count++;

}
template <class Type>
linkedListType<Type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>&
	otherList)
{
	first = NULL;
	copyList(otherList);
	cout << "copy const is called: " << endl;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
	destroyList();
}
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>&
	otherList)
{
	nodeType<Type>* newNode;
	nodeType<Type>* current;
	if (first != NULL)
		destroyList();
	if (otherList.first == NULL)
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first;
		count = otherList.count;
		first = new nodeType<Type>;
		first->info = current->info;
		first->link = NULL;
		last = first;
		current = current->link;
		while (current != NULL)
		{
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->link = NULL;
			last->link = newNode;
			last = newNode;
			current = current->link;
		}
	}
}


//array List Type functions
template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}
template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}
template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}
template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}
template <class elemType>
void arrayListType<elemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}
template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
(int location, const elemType& item) const
{
	return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt(int location, const elemType &
	insertItem)
{
	if (location < 0 || location >= maxSize)
		cerr << "The position of the item to be inserted "
		<< "is out of range" << endl;
	else
		if (length >= maxSize)
			cerr << "Cannot insert in a full list" << endl;
		else
		{
			for (int i = length; i > location; i--)
				list[i] = list[i - 1];
			list[location] = insertItem;
			length++;
		}
}
template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize)
		cerr << "Cannot insert in a full list" << endl;
	else
	{
		list[length] = insertItem;
		length++;
	}
}


template <class elemType>
void arrayListType<elemType>::retrieveAt
(int location, elemType & retItem) const
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be retrieved is "
		<< "out of range." << endl;
	else
		retItem = list[location];
}

template <class elemType>
void arrayListType<elemType>::replaceAt
(int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be replaced is "
		<< "out of range." << endl;
	else
		list[location] = repItem;
}

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
}
template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cerr << "The array size must be positive. Creating "
			<< "an array of size 100. " << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
delete[] list;
}

template <class elemType>
arrayListType<elemType>::arrayListType
(const arrayListType<elemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new elemType[maxSize];
	assert(list != NULL);
	for (int j = 0; j < length; j++)
		list[j] = otherList.list[j];
}

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
(const arrayListType<elemType>& otherList)
{
	if (this != &otherList)
	{
		delete[] list;
		maxSize = otherList.maxSize;
		length = otherList.length;
		list = new elemType[maxSize];
		assert(list != NULL);
		for (int i = 0; i < length; i++)
			list[i] = otherList.list[i];
	}
	return *this;
}

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;
	for (loc = 0; loc < length; loc++)
		if (list[loc] == item)
		{
			found = true;
			break;
		}
	if (found)
		return loc;
	else
		return -1;
}
template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;
	if (length == 0)
		list[length++] = insertItem;
	else if (length == maxSize)
		cerr << "Cannot insert in a full list." << endl;
	else
	{
		loc = seqSearch(insertItem);
		if (loc == -1)
			list[length++] = insertItem;
		else
			cerr << "the item to be inserted is already in "
			<< "the list. No duplicates are allowed." << endl;
	}
}
template<class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;
	if (length == 0)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list."
			<< endl;
	}
}
template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The location of the item to be removed "
		<< "is out of range" << endl;
	if (location == 0)
	{
		elemType temp;
		temp = list[location];
		list[location] = list[length - 1];
		list[length - 1] = temp;
		length--;
	}
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
}

template<class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem)
{
	int location;
	if (length == 0)
		cerr << "Cannot delete from an empty list.";
	else
	{
		location = seqSearch(removeItem);
		if (location == -1)
			cout << "Item to be deleted is not in the list.";
		while (location != -1)
		{
			removeAt(location);
			location = seqSearch(removeItem);
		}
	}
}