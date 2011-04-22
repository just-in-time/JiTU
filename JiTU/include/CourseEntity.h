#pragma once
#include "entityBase.h"
#include "Course.h"
#include "User.h"
using namespace System;

ref class CourseEntity : entityBase
{
public:
	CourseEntity(void);
	void AddCourse(Course *);
	void UpdateCourse(Course *);
	void DeleteCourse(Course *);
	Course * GetCourse(String^);
	Course * GetCourse(int);
	void AddStudent(User *);
	void AddInstructor(User *);
};
