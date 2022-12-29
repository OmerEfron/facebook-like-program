#include "memberException.h"
#include <string>
using namespace std;
string MemberException::what() const
{
	return string("Error while adding member to facebook.");
}

DuplicateNameException::DuplicateNameException(string name)
{
	message = string();
	message.append(name);
	message.append(" is already on facebook");
}

string DuplicateNameException::what() const
{
	return message;
}

string AddingMemberToHimself:: what() const
{
	return "cannot adding member to himself";
}

string InvalidBirthDate::what() const
{
	return "invalid date.";
}