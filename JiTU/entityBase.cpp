#include "StdAfx.h"
#include "entityBase.h"
using namespace MySql::Data::MySqlClient;

entityBase::entityBase(void)
{
	this->Connection = gcnew MySqlConnection("server=97.74.31.73;Uid=jituasu;Pwd=eap3THui;database=jituasu;Pooling=False");
}

void entityBase::AddParameter(System::String ^ name, MySql::Data::MySqlClient::MySqlDbType type, int size, System::Object ^ value)
{
	try
	{
		this->Command->Parameters->Add(name, type, size)->Value = value;
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
}

void entityBase::CloseConnection()
{
	this->Connection->Close();
}

int entityBase::ExecuteStoredProcedure()
{
	try
	{
		if(this->Connection->State != System::Data::ConnectionState::Open)
			this->OpenConnection();

		return this->Command->ExecuteNonQuery();
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		delete this->Command;
	}
}

void entityBase::FillDataSet(System::Data::DataSet ^ oDataSet)
{
	try
	{
		this->InitializeAdapter();
		this->DataAdapter->Fill(oDataSet);
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		delete this->Command;
		delete this->DataAdapter;
	}
}

void entityBase::FillDataSet(System::Data::DataSet ^ oDataSet, String^ name)
{
	try
	{
		this->InitializeAdapter();
		this->DataAdapter->Fill(oDataSet, name);
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		delete this->Command;
		delete this->DataAdapter;
	}
}

void entityBase::FillDataTable(System::Data::DataTable ^ oTable)
{
	try
	{
		this->InitializeAdapter();
		this->DataAdapter->Fill(oTable);
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
	finally
	{
		delete this->Command;
		delete this->DataAdapter;
	}
}

void entityBase::InitializeAdapter()
{
	try
	{
		this->DataAdapter = gcnew MySqlDataAdapter(this->Command);
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
}

void entityBase::InitializeCommand()
{
	if (!this->Command)
	{
		try
		{
			this->Command = gcnew MySqlCommand(this->SQL, this->Connection);

			if (!this->SQL->ToUpper()->StartsWith("SELECT ") &&
				!this->SQL->ToUpper()->StartsWith("INSERT ") &&
				!this->SQL->ToUpper()->StartsWith("UPDATE ") &&
				!this->SQL->ToUpper()->StartsWith("DELETE "))
				this->Command->CommandType = CommandType::StoredProcedure;
		}
		catch (MySqlException^ e)
		{
			throw gcnew System::Exception(e->Message, e->InnerException);
		}
	}
}

void entityBase::OpenConnection()
{
	try
	{
		if (this->Connection->State != ConnectionState::Open)
			this->Connection->Open();
	}
	catch (MySqlException^ e)
	{
		throw gcnew System::Exception(e->Message, e->InnerException);
	}
}