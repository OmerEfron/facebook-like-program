#include "memberException.h"
#include <string>
using namespace std;

string MemberToHimself::addMemberToHimself() const
{
	return "cannot add member to himself";
}
string MemberToHimself::removeMemberToHimself() const
{
	return "cannot remove member from himself";
}

string InvalidBirthDate::what() const
{
	return "invalid date.";
}
