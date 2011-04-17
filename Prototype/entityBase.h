#pragma once
using namespace System;
using namespace System::Data;
using namespace MySql::Data::MySqlClient;

ref class entityBase abstract //: System::IDisposable
{
public:
	entityBase(void);
	String^ SQL;
	MySqlConnection^ Connection;
	MySqlCommand^ Command;
	MySqlDataAdapter^ DataAdapter;

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
