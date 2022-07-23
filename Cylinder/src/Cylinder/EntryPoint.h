#pragma once

#ifdef CYL_PLATFORM_WINDOWS

extern Cylinder::Application* Cylinder::CreateApplication();

int main(int argc, char** argv)
{
	Cylinder::Log::Init();
	CYL_CORE_WARN("Initialized Core Logger!");
	CYL_INFO("Initialized Client Logger!");

	auto app = Cylinder::CreateApplication();
	app->Run();
	delete app;
}

#endif