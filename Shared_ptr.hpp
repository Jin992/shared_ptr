//
// Created by jin on 20.09.18.
//

#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

#include <iostream>
#include "Storage.hpp"

template <typename  T>
class Shared_ptr {
public:
	Shared_ptr();
	explicit Shared_ptr(T *p_value);
	Shared_ptr(const Shared_ptr<T> & other);
	Shared_ptr(Shared_ptr<T> &&other) noexcept;
	~Shared_ptr();

	T& operator*();
	T* operator->();
	Shared_ptr& operator=(const Shared_ptr<T> &other);
	Shared_ptr& operator=(Shared_ptr<T> &&other) noexcept;


private:
	Storage*	_cnt_reference;
	T*			_ptr;
};


template <typename T>
Shared_ptr<T>::Shared_ptr():_ptr(nullptr), _cnt_reference(nullptr)
{
	_cnt_reference = new Storage();
	_cnt_reference->addRef();
}

template <typename T>
Shared_ptr<T>::Shared_ptr(T *p_value): _ptr(p_value), _cnt_reference(nullptr)
{
	_cnt_reference = new Storage();
	_cnt_reference->addRef();
}

template <typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T> & other)
			: _ptr(other._ptr),
			  _cnt_reference(other._cnt_reference)
{
	_cnt_reference->addRef();
}

template <typename T>
Shared_ptr<T>::Shared_ptr(Shared_ptr<T> &&other) noexcept
			: _ptr(std::move(other._ptr)),
			  _cnt_reference(std::move(other._cnt_reference))
{
			  	std::cout << "Move constructor" << std::endl;
	_cnt_reference->addRef();
}

template <typename T>
Shared_ptr<T>::~Shared_ptr()
{
	if (_cnt_reference->release() == 0)
	{
		delete _ptr;
		delete _cnt_reference;
	}
}

template <typename T>
T& Shared_ptr<T>::operator*()
{
	return *_ptr;
}

template <typename T>
T*  Shared_ptr<T>::operator->()
{
	return _ptr;
}

template <typename T>
Shared_ptr<T>&  Shared_ptr<T>::operator=(const Shared_ptr<T> &other)
{
	if (this != &other)
	{
		if (_cnt_reference->release() == 0)
		{
			delete  _ptr;
			delete  _cnt_reference;
		}
		_ptr = other._ptr;
		_cnt_reference = other._cnt_reference;
		_cnt_reference->addRef();
	}
	return *this;
}

template <typename T>
Shared_ptr<T>&  Shared_ptr<T>::operator=(Shared_ptr<T> &&other) noexcept
{
	if (this != &other)
	{
		if (_cnt_reference->release() == 0)
		{
			delete  _ptr;
			delete  _cnt_reference;
		}
		_ptr = std::move(other._ptr);
		_cnt_reference = std::move(other._cnt_reference);
		_cnt_reference->addRef();
	}
	return *this;
}
#endif //SHARED_PTR_HPP














































