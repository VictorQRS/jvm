#pragma once

#include "base.hpp"

typedef uint8_t  u1;
typedef uint16_t u2;
typedef uint32_t u4;
typedef uint64_t u8;
typedef int8_t   i1;
typedef int16_t  i2;
typedef int32_t  i4;
typedef int64_t  i8;

union op4 {
	uint8_t ui1;
	uint16_t ui2;
	uint32_t ui4;
	int8_t i1;
	int16_t i2;
	int32_t i4;
	float f;
};

union op8 {
	double lf;
	uint64_t ull;
	int64_t ll;
};

struct Data {
	u1 type;
	op4 value;
	u4 tam;
};

struct BigData {
	u1 type;
	op8 value;
};

struct Array {
	u4 type;
	u4 size;
	void * array;
};