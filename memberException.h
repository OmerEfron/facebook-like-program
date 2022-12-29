#ifndef MEMBER_EXCEPTION
#define MEMBER_EXCEPTION
#include <string>

class MemberException
{ 
public:
	virtual std::string what() const;
};

class DuplicateNameException : public MemberException
{
private:
	std::string message;
public:
	DuplicateNameException(std::string name);
	virtual std::string what() const;
};

class AddingMemberToHimself : public MemberException
{
public:
	virtual std::string what() const;
};

class InvalidBirthDate : public MemberException
{

public:
	virtual std::string what() const;
};


#endif // !MEMBER_EXCEPTION
