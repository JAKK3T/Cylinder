#pragma once

#ifdef CYL_PLATFORM_WINDOWS

extern Cylinder::Application* Cylinder::CreateApplication();

int main(int argc, char** argv)
{
	printf("Cylinder Engine");
	auto app = Cylinder::CreateApplication();
	app->Run();
	delete app;
}

#endif