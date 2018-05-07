#pragma once

#include "bit.hpp"

namespace jvm {
	enum ACC_FLAGS : uint16_t {
		PUBLIC     = 1,     // Declared public; may be accessed = from outside its package.
		FINAL      = 16,	// Declared final; no subclasses allowed.
		SUPER      = 32,	// Treat superclass methods specially when invoked by the invokespecial instruction.
		INTERFACE  = 512,   // Is an interface, not a class.
		ABSTRACT   = 1024,  // Declared abstract; must not be instantiated.
		SYNTHETIC  = 4096,  // Declared synthetic; not present in the source code.
		ANNOTATION = 8192,  // Declared as an annotation type.
		ENUM       = 16382, // Declared as an enum type.
	};
	
	enum CP_TAGS : uint16_t {
		Class              = 7,
		FieldRef           = 9,
		MethodRef          = 10,
		InterfaceMethodRef = 11,
		String             = 8,
		Integer	           = 3,
		Float              = 4,
		Long               = 5,
		Double             = 6,
		NameAndType        = 12,
		Utf8               = 1,
		MethodHandle       = 15,
		MethodType         = 16,
		InvokeDynamic      = 18
	};

	class CP_Entry {
	public:
		static CP_TAGS tag;
	};

	struct CP_Class : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Fieldref : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Methodref : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_InterfaceMethodref : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_String : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Integer : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Float : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Long : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Double : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_NameAndType : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_Utf8 : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_MethodHandle : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_MethodType : public CP_Entry {
		HalfWord name_index;
	};

	struct CP_InvokeDynamic : public CP_Entry {
		HalfWord name_index;
	};

}