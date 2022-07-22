#pragma once

#include "Core.h"

namespace Cylinder {

	class CYLINDER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//Will be defined in client
	Application* CreateApplication();
}