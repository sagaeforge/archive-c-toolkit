#pragma once

#include "JString.hpp"

class JSON
{
public:
	JSON();
	JSON(JString p_STR);
	JSON(FILE p_FILE);
	JSON(JSON *p_JSON);
	~JSON();

private:

};

class JSONObject
{
public:
	JSONObject();
	JSONObject(bool p_Value);
	JSONObject(int p_Value);
	JSONObject(double p_Value);
	JSONObject(JString p_Value);
	~JSONObject();

private:

};


class JSONArray
{
public:
	JSONArray();
	JSONArray(bool p_Value);
	JSONArray(int p_Value);
	JSONArray(double p_Value);
	JSONArray(JString p_Value);
	~JSONArray();

private:

};
