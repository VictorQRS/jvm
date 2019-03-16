#include "variables.hpp"

namespace jvm {

	// TODO: implement this
	// Variables::Variables(uint32_t n) {
	// 	vec = new op4[n];
	// }

	Variables::Variables() {}

	Variables::~Variables() {
		// TODO: implement this
		//delete[] vec;
	}

	op4 Variables::get4(u4 idx) {
		return vec[idx];
	}

	op8 Variables::get8(u4 idx) {
		return Converter::to_op8(vec[idx], vec[idx+1]);
	}

	void Variables::set(u4 idx, op4 value) {
		vec[idx] = value;
	}

	void Variables::set(u4 idx, u4 value) {
		vec[idx].ui4 = value;
	}

	void Variables::set(u4 idx, op8 value) {
		auto result  = Converter::to_op4(value);
		vec[idx]     = result[0];
		vec[idx + 1] = result[1];
	}

	void Variables::set(u4 idx, u8 value) {
		op8 aux;

		aux.ull = value;

		auto result  = Converter::to_op4(aux);
		vec[idx]     = result[0];
		vec[idx + 1] = result[1];
	}

	void Variables::setSize(u4 size) {
		vec.resize(size);
	}

};
