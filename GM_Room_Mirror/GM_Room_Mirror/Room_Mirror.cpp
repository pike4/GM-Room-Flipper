#include "pugixml.hpp"
#include <iostream>

int main()
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("Room.xml");


	pugi::xml_node mainNode = doc.child("room");

	pugi::xml_node workNode = mainNode.child("instances");
	workNode = workNode.first_child();
	std::string workName = workNode.name();

	int x;
	const int max_X = 800 - 16;

	while(!workName.empty())
	{
		x = atoi(workNode.attribute("x").value());

		x = max_X - x;

		workNode.attribute("x").set_value(x);

		workNode = workNode.next_sibling();
		workName = workNode.name();
	}

	workNode = mainNode.child("tiles").first_child();
	workName = workNode.name();

	while(!workName.empty())
	{
				x = atoi(workNode.attribute("x").value());

		x = max_X - x;

		workNode.attribute("x").set_value(x);

		workNode = workNode.next_sibling();
		workName = workNode.name();
	}
	if(
	doc.save_file("PleasePleaseWork.room.gmx"))
	{
		std::cout<<"It worked"<<std::endl;
	}
	system("PAUSE");
	return 0;
}