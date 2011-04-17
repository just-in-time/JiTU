
#include "UserEntity.h"
#include "ManagedToStd.h"

UserEntity::UserEntity(void)
{
}

void UserEntity::AddUser(User * theUser)
{
	try
	{
		this->SQL = "INSERT INTO `users` (`user_name`, `full_name`, `role_id`, `password`) " +
			"VALUES (\"" + ManagedToStd::toManaged(theUser->getUsername()) + "\", \"" + 
			ManagedToStd::toManaged(theUser->getFullName()) + "\", " + theUser->getRole() + 
			", \"" + ManagedToStd::toManaged(theUser->getPassword()) + "\");";
		this->InitializeCommand();

		if (this->ExecuteStoredProcedure() == 0)
			throw gcnew System::Exception("The user data was not added to the database.");
	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
}

void UserEntity::UpdateUser(User * theUser)
{
}

void UserEntity::DeleteUser(User * theUser)
{
}

User * UserEntity::GetUser(System::String ^)
{
	User * newUser = new User(0);

	return newUser;
}
