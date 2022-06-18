#pragma once

template <typename T>
class nObject
{
private:
	T m_Value;

public:
	T get() const { return m_Value; }
	void set(T Value) const { m_Value = Value; }
};
