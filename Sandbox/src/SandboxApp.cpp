#include <Spearmint.h>

class Sandbox : public Spearmint::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}

};

Spearmint::Application* Spearmint::CreateApplication() {
	return new Sandbox();
}