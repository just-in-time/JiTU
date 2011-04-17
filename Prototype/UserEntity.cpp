
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
		this->OpenConnection();

		if (this->ExecuteStoredProcedure() == 0)
			throw gcnew System::Exception("The user data was not added to the database.");
	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}
}

void UserEntity::UpdateUser(User * theUser)
{
	try
	{
		this->SQL = "UPDATE `users` u " +
			"SET u.`user_name` = \"" + ManagedToStd::toManaged(theUser->getUsername()) + "\", " +
			"u.`full_name` = \"" + ManagedToStd::toManaged(theUser->getFullName()) + "\", " +
			"u.`role_id` = " + theUser->getRole() + ", " +
			"u.`password` = \"" + ManagedToStd::toManaged(theUser->getPassword()) + "\" " +
			"WHERE u.`user_id` = " + theUser->getID() + ";";
		this->InitializeCommand();
		this->OpenConnection();

		if (this->ExecuteStoredProcedure() == 0)
			throw gcnew System::Exception("The user data was not updated in the database.");
	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}

}

void UserEntity::DeleteUser(User * theUser)
{
	try
	{
		this->SQL = "DELETE FROM `users` WHERE `user_id` = " + theUser->getID() + ";";
		this->InitializeCommand();
		this->OpenConnection();

		if (this->ExecuteStoredProcedure() == 0)
			throw gcnew System::Exception("The user data was not updated in the database.");
	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}

}

User * UserEntity::GetUser(System::String ^ UserName)
{
	User * newUser;

	try
	{
		this->SQL = "SELECT * FROM `users` u WHERE u.`user_name` = " + UserName + ";";
		this->InitializeCommand();
		this->OpenConnection();

		this->DataReader = this->Command->ExecuteReader();

		if (this->DataReader->HasRows)
		{
			this->DataReader->Read();

			newUser = new User((int)this->DataReader["user_id"]);
			newUser->setFullName(*(ManagedToStd::toStd(this->DataReader["full_name"]->ToString())));
			newUser->setPassword(*(ManagedToStd::toStd(this->DataReader["password"]->ToString())));
			newUser->setRole((int)this->DataReader["role_id"]);
			newUser->setUsername(*(ManagedToStd::toStd(this->DataReader["user_name"]->ToString())));
		}
		else
			throw gcnew System::Exception("The user name \"" + UserName + "\" was not found in the database.");

	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}


	return newUser;
}
