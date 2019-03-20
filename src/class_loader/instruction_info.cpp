#include "instruction_info.hpp"
#include "../util/JvmException.hpp"

namespace jvm {

	// general
	void InstructionInfo::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << std::endl;
	}

	uint32_t InstructionInfo::fillParams (uint32_t idx, std::vector<u1>& data) {
		return 0;
	}

	// bipush
	void OPINFObipush::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +byte << std::endl;
	}

	uint32_t OPINFObipush::fillParams (uint32_t idx, std::vector<u1>& data) {
		byte = Converter::to_i1(data[idx+1]);
		return 1;
	}

	// sipush
	void OPINFOsipush::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << value << std::endl;
	}

	uint32_t OPINFOsipush::fillParams (uint32_t idx, std::vector<u1>& data) {
		value = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ldc
	void OPINFOldc::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOldc::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// ldc_w
	void OPINFOldc_w::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOldc_w::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ldc2_w
	void OPINFOldc2_w::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOldc2_w::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// iload
	void OPINFOiload::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOiload::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// lload
	void OPINFOlload::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOlload::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// fload
	void OPINFOfload::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOfload::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// dload
	void OPINFOdload::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOdload::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// aload
	void OPINFOaload::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOaload::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// istore
	void OPINFOistore::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOistore::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// lstore
	void OPINFOlstore::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOlstore::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// fstore
	void OPINFOfstore::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOfstore::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// dstore
	void OPINFOdstore::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOdstore::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// astore
	void OPINFOastore::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOastore::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// iinc
	void OPINFOiinc::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << " " << +constant << std::endl;
	}

	uint32_t OPINFOiinc::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		constant = Converter::to_i1(data[idx+2]);
		return 2;
	}

	// ifeq
	void OPINFOifeq::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifeq::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ifne
	void OPINFOifne::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifne::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// iflt
	void OPINFOiflt::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOiflt::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ifge
	void OPINFOifge::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifge::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ifgt
	void OPINFOifgt::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifgt::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ifle
	void OPINFOifle::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifle::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmpeq
	void OPINFOif_icmpeq::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmpeq::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmpne
	void OPINFOif_icmpne::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmpne::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmplt
	void OPINFOif_icmplt::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmplt::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmpge
	void OPINFOif_icmpge::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmpge::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmpgt
	void OPINFOif_icmpgt::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmpgt::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_icmple
	void OPINFOif_icmple::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_icmple::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_acmpeq
	void OPINFOif_acmpeq::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_acmpeq::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// if_acmpne
	void OPINFOif_acmpne::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOif_acmpne::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// goto
	void OPINFOgoto::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOgoto::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// TODO: finish retrieve data in classes: continue implementation from iinc, see https://en.wikipedia.org/wiki/Java_bytecode_instruction_listings
	// TODO: print the data retrieved
	// TODO: implements variable arguments
	// TODO: verify if the data is retrieveing correct

	// jsr
	void OPINFOjsr::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOjsr::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ret
	void OPINFOret::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << std::endl;
	}

	uint32_t OPINFOret::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = data[idx+1];
		return 1;
	}

	// tableswitch
	void OPINFOtableswitch::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << defaultbyte << " " << low << " " << high; // TODO: << " " << jumpOffsets << std::endl;
	}

	// TODO: check later for correctness
	uint32_t OPINFOtableswitch::fillParams (uint32_t idx, std::vector<u1>& data) {
		uint32_t i = idx + 1;

		i += (i % 4); // this jump is needed! A tableswitch is a variable-length instruction. Immediately after the tableswitch opcode, between zero and three bytes must act as padding, such that defaultbyte1 begins at an address that is a multiple of four bytes from the start of the current method (the opcode of its first instruction).

		defaultbyte = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;
		low         = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;
		high        = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;

		auto n = high - low + 1;

		if (low <= high) {
			throw JvmException("Invalid tableswitch");
		}

		jumpOffsets.resize(n);

		for (int j = 0; j < n; j++, i += 4) {
			jumpOffsets[j] = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]);
		}

		return jmp = i - idx - 1; // 16+
	}

	// OPINFOlookupswitch
	void OPINFOlookupswitch::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << npairs << " ";

		for(auto& sm_pair : pairs)
			os << sm_pair.first << " ";

		os << defaultbyte << std::endl;
	}

	// TODO: check later for correctness
	uint32_t OPINFOlookupswitch::fillParams (uint32_t idx, std::vector<u1>& data) {
		uint32_t i = idx + 1;

		i += (i % 4); // this jump is needed! A tableswitch is a variable-length instruction. Immediately after the tableswitch opcode, between zero and three bytes must act as padding, such that defaultbyte1 begins at an address that is a multiple of four bytes from the start of the current method (the opcode of its first instruction).

		defaultbyte = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;
		npairs      = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;

		if (npairs < 0) {
			throw JvmException("Invalid tableswitch");
		}

		for (int j = 0; j < npairs; j++, i += 4) {
			auto match  = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]); i += 4;
			auto value  = Converter::to_i4(data[i], data[i+1], data[i+2], data[i+3]);

			pairs[match] = value;
		}

		return jmp = i - idx - 1; // 8+
	}

	// getstatic
	void OPINFOgetstatic::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOgetstatic::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// putstatic
	void OPINFOputstatic::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOputstatic::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// getfield
	void OPINFOgetfield::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOgetfield::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// putfield
	void OPINFOputfield::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOputfield::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// invokevirtual
	void OPINFOinvokevirtual::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOinvokevirtual::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// invokespecial
	void OPINFOinvokespecial::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOinvokespecial::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// invokestatic
	void OPINFOinvokestatic::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOinvokestatic::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// invokeinterface
	void OPINFOinvokeinterface::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << " " << +count << std::endl;
	}

	uint32_t OPINFOinvokeinterface::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		count = data[idx+3];

		if(!count)
			throw JvmException("Invalid invokeinterface: the value of count must not be zero");

		if(!data[idx+4])
			throw JvmException("Invalid invokeinterface: the value of the last argument must be zero");

		return 4;
	}

	// invokedynamic
	void OPINFOinvokedynamic::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << " 0 0" << std::endl;
	}

	uint32_t OPINFOinvokedynamic::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		if(!data[idx+3] || !data[idx+4]) {
			throw JvmException("Invalid invokedynamic: the value of the last 2 arguments must be zero");
		}
		return 4;
	}

	// new
	void OPINFOnew::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOnew::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// newarray
	void OPINFOnewarray::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +atype << std::endl;
	}

	uint32_t OPINFOnewarray::fillParams (uint32_t idx, std::vector<u1>& data) {
		atype = data[idx+1];
		return 1;
	}

	// anewarray
	void OPINFOanewarray::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOanewarray::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// checkcast
	void OPINFOcheckcast::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOcheckcast::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// instanceof
	void OPINFOinstanceof::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << index << std::endl;
	}

	uint32_t OPINFOinstanceof::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		return 2;
	}

	// wide
	void OPINFOwide::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +opcode << " " << index << " " << countbyte << std::endl;
	}

	uint32_t OPINFOwide::fillParams (uint32_t idx, std::vector<u1>& data) {
		OPINFOiinc iinc;

		opcode = data[idx + 1];

		index = Converter::to_u2(data[idx + 2], data[idx + 3]);

		if (opcode == iinc.opcode) {
			countbyte = Converter::to_u2(data[idx + 4], data[idx + 5]);
			return jmp = 5;
		}

		return jmp = 3;
	}

	// multianewarray
	void OPINFOmultianewarray::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << +index << " " << cl[index]->toString(cl) << " dim " << +dimensions << std::endl;
	}

	uint32_t OPINFOmultianewarray::fillParams (uint32_t idx, std::vector<u1>& data) {
		index = Converter::to_u2(data[idx+1], data[idx+2]);
		dimensions = data[idx+3];

		if(dimensions < 1u)
			throw JvmException("Invalid multianewarray: the number of dimensions of the array must be greater than or equal to 1");

		return 3;
	}

	// ifnull
	void OPINFOifnull::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifnull::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// ifnonnull
	void OPINFOifnonnull::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOifnonnull::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i2(data[idx+1], data[idx+2]);
		return 2;
	}

	// goto_w
	void OPINFOgoto_w::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOgoto_w::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i4(data[idx+1], data[idx+2], data[idx+3], data[idx+4]);
		return 4;
	}

	// jsr_w
	void OPINFOjsr_w::printToStream(std::ostream& os, std::string& prefix, ConstantPool& cl) {
		os << prefix << this->name << " " << branchoffset << std::endl;
	}

	uint32_t OPINFOjsr_w::fillParams (uint32_t idx, std::vector<u1>& data) {
		branchoffset = Converter::to_i4(data[idx+1], data[idx+2], data[idx+3], data[idx+4]);
		return 4;
	}
}
