#pragma once

#include <functional>

enum class ActionType
{
	manual,
	automatic
};

struct PayLoad
{
	ActionType action_type;
	std::function<void()> action;
};
