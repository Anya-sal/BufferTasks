#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	HANDLE hStd0ut, hStdIn; 
	DWORD dwWritten, dwRead; 
	char buffer[80]; 
	char str[] = "Input any string:";
	char c; 
	hStd0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	if (hStd0ut == INVALID_HANDLE_VALUE || hStdIn == INVALID_HANDLE_VALUE)
	{
		cout << "Get standard handle failed." << endl;
		return GetLastError();
	}
	if (!WriteConsole(hStd0ut, &str, sizeof(str), &dwWritten, NULL)) 
	{
		cout << "Write console failed." << endl; return GetLastError();
	}
	
	if (!ReadConsole(hStdIn, &buffer, sizeof(buffer), &dwRead, NULL)) {
		cout << "Read console failed." << endl;
		return GetLastError();
	}
	
	cout << "Input any char to exit: "; cin >> c;
	return 0;
}