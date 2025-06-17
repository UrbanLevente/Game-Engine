#pragma once
#include <vector>
#include <functional>
#include <utility>
#include <cstddef>

template<typename Signature>
class Event;

template<typename Ret, typename... Args>
class Event<Ret(Args...)> {
public:
	using Callback = std::function<Ret(Args...)>;
	using ConnectionID = std::size_t;

	ConnectionID Connect(Callback func) {
		ConnectionID id = nextId++;
		subscribers.emplace_back(id, std::move(func));
		return id;
	}

	void Disconnect(ConnectionID id) {
		for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
			if (it->first == id) {
				subscribers.erase(it);
				break;
			}
		}
	}

	void Fire(Args... args) {
		for (auto& [id, func] : subscribers) {
			if (func) func(args...);
		}
	}

private:
	std::vector<std::pair<ConnectionID, Callback>> subscribers;
	ConnectionID nextId = 0;
};
