#ifndef _REFERENCE_ERROR_HPP
#define _REFERENCE_ERROR_HPP

class ReferenceError {

private:
	Reference reference;
	ReferenceError();

public:
	ReferenceError(Reference reference);

	Reference getReference();
};
#endif