#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {
	if (b) {
		*p_bits |= (1L << pos);
	}
	else {
		*p_bits &= ~(1L << pos);
	}
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	return operator=(static_cast<bool>(rhs));
}

BitReference::operator bool() const {
	return (*p_bits & (1L << pos)) != 0;
}
