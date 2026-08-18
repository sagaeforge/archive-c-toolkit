#pragma once

template <typename T>
class Object
{
public:
	Object();
	Object(T p_Value);
	~Object();

private:
	T m_Value;
};
