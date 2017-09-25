#include "MyForm.h"


[STAThreadAttribute]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyForm form;
	Application::Run(%form);
}