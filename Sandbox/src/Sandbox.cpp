#include <Cylinder.h>

class Sandbox : public Cylinder::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Cylinder::Application* Cylinder::CreateApplication()
{
	return new Sandbox();
}