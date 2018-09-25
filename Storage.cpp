//
// Created by jin on 21.09.18.
//

#include "Storage.hpp"


void Storage::addRef()
{
	_count++;
}

int Storage::release()
{
	return --_count;
}