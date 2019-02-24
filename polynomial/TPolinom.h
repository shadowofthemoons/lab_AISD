#pragma once
#include "HeadRing.h"

class TPolinom : public THeadRing {
public:
	TPolinom();
	TPolinom(const TPolinom &q);
	TPolinom & operator+=( const TPolinom &q);
	TPolinom & operator+(const TPolinom &q); // сложение полиномов
	TPolinom & operator=(const TPolinom &q);
};
