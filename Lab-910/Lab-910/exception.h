#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception {
protected:
	const char* message;
public:
	Exception(const char* m)
	{
		this->message = m;
	}
	const char* getMessage()
	{
		return message;
	}
};

#endif