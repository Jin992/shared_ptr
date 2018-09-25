//
// Created by jin on 21.09.18.
//

#ifndef STORAGE_HPP
#define STORAGE_HPP

class Storage
{
public:
	void addRef();
	int release();

private:
	int _count;
};


#endif //SHARED_PTR_STORAGE_HPP
