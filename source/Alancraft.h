#include "Application/Application.h"

class Alancraft final : public Application
{
public:
	Alancraft();
	~Alancraft();

private:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Terminate() override;
};