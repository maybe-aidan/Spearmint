#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef SM_PLATFORM_WINDOWS

extern Spearmint::Application* Spearmint::CreateApplication();

int main(int argc, char** argv) {
	Spearmint::Log::Init();
	SM_CORE_WARN("Initialized Log!");
	int a = 5;
	SM_INFO("Hello! Var={0}", a);

	auto app = Spearmint::CreateApplication();
	app->Run();
	delete app;

}

#endif

#endif
