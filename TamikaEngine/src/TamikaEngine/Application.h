#pragma once
#include "Core.h"

namespace TamikaEngine {

	class TE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

