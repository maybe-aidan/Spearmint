#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef SM_PLATFORM_WINDOWS

extern Spearmint::Application* Spearmint::CreateApplication();

int main(int argc, char** argv) {
	printf("Spearmint Engine\n");
	auto app = Spearmint::CreateApplication();
	app->Run();
	delete app;

}

#endif

#endif
