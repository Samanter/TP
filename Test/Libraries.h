#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace msclr::interop;
using namespace System::Runtime::InteropServices;

void MarshalString(System::String^ s, std::string& outputstring) {
	const char* kPtoC = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	outputstring = kPtoC;
	Marshal::FreeHGlobal(System::IntPtr((void*)kPtoC));
}