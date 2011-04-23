#ifndef __SECURITYFUNCTIONS__
#define __SECURITYFUNCTIONS__
#include <string>
#include "stdafx.h"

using namespace cli;
using namespace std;
using namespace System;
using namespace System::Security;
using namespace System::Security::Cryptography;

namespace security {

String^ Sha1(String^);

};
#endif