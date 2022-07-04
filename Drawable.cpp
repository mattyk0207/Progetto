#inculde "Drawable.hpp"

Drawable::Drawable()																				// parent di hero
{ 
	int y = x = 0;
	chtype icon = ' ';
}

Drawable::Drawable(int y, int x, chtype ch)
{
	this->y = y;
	this->x = x;
	this->icon = ch;
}

int Drawable::gety()
{
	return y;
}

int Drawable::getx()
{
	return x;
}

schtype Drawable::getIcon()
{
	return icon;
}
