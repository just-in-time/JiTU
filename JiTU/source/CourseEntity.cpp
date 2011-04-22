
#include "CourseEntity.h"
#include "ManagedToStd.h"

CourseEntity::CourseEntity(void)
{
}

void CourseEntity::AddCourse(Course * theCourse)
{
}

void CourseEntity::AddInstructor(User * theInstructor)
{
}

void CourseEntity::AddStudent(User * theStudent)
{
}

void CourseEntity::DeleteCourse(Course * theCourse)
{
}

Course * CourseEntity::GetCourse(int CourseID)
{
	Course * newCourse;
	
	try
	{
		this->SQL = "SELECT * FROM `courses` c WHERE c.`course_id` = " + CourseID + ";";
		this->InitializeCommand();
		this->OpenConnection();

		this->DataReader = this->Command->ExecuteReader();

		if (this->DataReader->HasRows)
		{
			this->DataReader->Read();

			newCourse = new Course((int)this->DataReader["course_id"]);
			newCourse->setCourseName(*(ManagedToStd::toStd(this->DataReader["name"]->ToString())));
		}
		else
			throw gcnew System::Exception("The course ID \"" + CourseID + "\" was not found in the database.");

	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}

return newCourse;
}

Course * CourseEntity::GetCourse(System::String^ CourseName)
{
	Course * newCourse;

	try
	{
		this->SQL = "SELECT * FROM `courses` c WHERE c.`name` = " + CourseName + ";";
		this->InitializeCommand();
		this->OpenConnection();

		this->DataReader = this->Command->ExecuteReader();

		if (this->DataReader->HasRows)
		{
			this->DataReader->Read();

			newCourse = new Course((int)this->DataReader["course_id"]);
			newCourse->setCourseName(*(ManagedToStd::toStd(this->DataReader["name"]->ToString())));
		}
		else
			throw gcnew System::Exception("The course name \"" + CourseName + "\" was not found in the database.");

	}
	catch(System::Exception^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		this->CloseConnection();
	}

	return newCourse;
}

void CourseEntity::UpdateCourse(Course * theCourse)
{
}