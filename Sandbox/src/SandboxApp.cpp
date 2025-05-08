#include <nuts.h>
class Sandbox :public nuts::Application {
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};
nuts::Application* nuts::CreateApplication()
{
	return new Sandbox();
}