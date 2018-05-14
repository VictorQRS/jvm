#include <iostream>
#include "reader.hpp"
#include "attribute.hpp"

namespace jvm {
	AttributeInfo::AttributeInfo(Reader &reader) {
		Read(reader);
	}

	void AttributeInfo::printToStream(std::ostream &os, ConstantPool &cp) {
		char buffer[5];
		auto name = cp[name_index.value.number];
		auto& characters = name->as<CP_Utf8>();
		
		os << "Attribute: " << characters << std::endl;
		os << "\tLength: " << length.value.number << std::endl;
		os << "\tBytes:  ";

		for (auto& byte : info) {
			sprintf(buffer, "%.2X ", byte);
			os << buffer;
		}

		os << std::endl;
	}

	void AttributeInfo::Read(Reader &reader) {
		name_index = reader.getNextHalfWord();
		length = reader.getNextWord();

		for (int i = 0; i < length.value.number; ++i) {
			info.push_back(reader.getNextByte().value.number);
		}
	}
}
