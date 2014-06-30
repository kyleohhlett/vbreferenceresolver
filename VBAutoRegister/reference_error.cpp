#include "reference.hpp"
#include "reference_error.hpp"

ReferenceError::ReferenceError() {

}

ReferenceError::ReferenceError(Reference reference) {
	
	this->reference = reference;
}

Reference ReferenceError::getReference() {

	return this->reference;
}