#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern TamikaEngine::Application* TamikaEngine::CreateApplication();

int main(int argc, char** argv)
{
	TamikaEngine::Log::Init();
	TE_CORE_ERROR("Initialize Error Core Log");
	TE_INFO("Initialize Info Client Log");

	int a = 5;
	TE_ERROR("Hello! Var={0}", a);

	auto app = TamikaEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
