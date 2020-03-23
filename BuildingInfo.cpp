#include "stdafx.h"
#include "BuildingInfo.h"
#include  <fstream>


void BuildingInfo::Init()
{
	map<int, string> materialList;
	materialList.insert(make_pair(2, "Wood"));
	materialList.insert(make_pair(3, "Stone"));
	materialList.insert(make_pair(4, "Dirt"));
	materialList.insert(make_pair(5, "Water"));
	materialList.insert(make_pair(6, "Ore"));
	materialList.insert(make_pair(7, "Brick"));
	materialList.insert(make_pair(8, "Steel"));
	materialList.insert(make_pair(9, "Plank"));


	string nowString;
	vector<string> nowData;

	fstream stream;
	stream.open("Resources/Data/BuildData.csv", ios::in);

	
	while (true)
	{
		stream >> nowString;
		if (stream.eof())
			break;
		char* data = strtok(const_cast<char*>(nowString.c_str()), ",");
		for (; data != NULL; data = strtok(NULL, ","))
			nowData.push_back(data);

		tagBuildingInfo nowInfo;
		nowInfo.time = atoi(nowData[1].c_str());


		for (int i = 2; i < nowData.size(); i++)
			nowInfo.material.insert(make_pair(materialList[i], atoi(nowData[i].c_str())));
		info[nowData[0]] = nowInfo;
		nowData.clear();
	}

	stream.close();

	map<string, tagBuildingInfo> check = GetBuildingInfo();

}
