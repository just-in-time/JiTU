#pragma once
#include "stdafx.h"
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;


#ifndef HOST
#define HOST ("97.74.31.93")
#endif

ref class entityBase abstract //: System::IDisposable
{
public:
	entityBase(void);
	String^ SQL;
	MySqlConnection^ Connection;
	MySqlCommand^ Command;
	MySqlDataAdapter^ DataAdapter;
	MySqlDataReader^ DataReader;

	void AddParameter(String^, MySqlDbType, int, Object^);
	void CloseConnection();
	int ExecuteStoredProcedure();
	void FillDataSet(DataSet^);
	void FillDataSet(DataSet^, String^);
	void FillDataTable(DataTable^);
	void InitializeAdapter();
	void InitializeCommand();
	void OpenConnection();

	//virtual void Dispose() override;
private:
	bool disposed;
};
