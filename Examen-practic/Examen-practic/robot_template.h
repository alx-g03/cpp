#ifndef ROBOT_TEMPLATE_H
#define ROBOT_TEMPLATE_H

#include <vector>

template <class T>
class RobotTemplate {
private:
	int battCap;
	std::vector<T> elems;
public:
	RobotTemplate();
	~RobotTemplate();
	void add(T& e);
	bool find(T& e);
	bool update(T& eVeche, T& eNoua);
	bool remove(T& e);
	std::vector<T> getAll();
	int getSize();
};

template <class T>
inline RobotTemplate<T>::RobotTemplate() 
{
	this->battCap = 100;
}

template <class T>
inline RobotTemplate<T>::~RobotTemplate() {}

template <class T>
inline void RobotTemplate<T>::add(T& e)
{
	this->elems.push_back(e);
}

template <class T>
inline bool RobotTemplate<T>::find(T& e)
{
	typename std::vector<T>::iterator it = std::find(this->elems.begin(), this->elems.end(), e);
	if (it != this->elems.end())
		return true;
	return false;
}

template <class T>
inline bool RobotTemplate<T>::update(T& eVeche, T& eNoua)
{
	typename std::vector<T>::iterator it = std::find(this->elems.begin(), this->elems.end(), eVeche);
	if (it != this->elems.end())
	{
		*it = eNoua;
		return true;
	}
	return false;
}

template <class T>
inline bool RobotTemplate<T>::remove(T& e)
{
	typename std::vector<T>::iterator it = std::find(this->elems.begin(), this->elems.end(), e);
	if (it != this->elems.end())
	{
		this->elems.erase(it);
		return true;
	}
	return false;
}

template <class T>
inline std::vector<T> RobotTemplate<T>::getAll()
{
	return this->elems;
}

template <class T>
inline int RobotTemplate<T>::getSize()
{
	return this->elems.size();
}

#endif