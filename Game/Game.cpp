#include "Core/Core.h"

void CollideWith(int otherEntityId) {
	std::cout << "Player detected collision.\n";
	Engine::Events::OnCollision.Fire(otherEntityId);
}

int main() {
	auto collisionEvent = Engine::Events::OnCollision.Connect([](int id) {
		std::cout << "Collision with entity: " << id << "\n";
	});

	CollideWith(42);

	Engine::Events::OnCollision.Disconnect(collisionEvent);

	CollideWith(42);

	return 0;
}