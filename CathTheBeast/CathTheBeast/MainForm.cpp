#include "MainForm.h"

using namespace CathTheBeast;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault(false);

	//�������� �������� ���� � ��� ������
	Application::Run(gcnew MainForm());
	return 0;
}

