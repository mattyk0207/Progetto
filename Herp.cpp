#incude Hero.hpp

Hero::Hero()
{
	this->y = this->x = 0;
	this->icon = 'P';
}

Hero::Hero(int y, int x)
{
	this->y = y;
	this->x = x;
	this->icon = 'P';
}

Direction Hero::getDirection()
{
	return cur_direction;
}

void Hero::setDirection(Direction newdir)
{
	cur_direction = newdir;
}

void Hero::moveHero()
{ 																							// movimento in se
	int row = Drawable::gety();
	int col = Drawable::getx();
	switch (cur_direction)
	{
	case down:
		row++;
		break;
	case up:
		row--;
		break;
	case sx:
		col--;
		break;
	case dx:
		col++;
		break;
	default:
		break;
	}
	this->y = row;
	this->x = col;
}

int Hero::getx()
{
	return Drawable::getx();
}
int Hero::gety()
{
	return Drawable::gety();
}
int Hero::getIcon()
{
	return Drawable::getIcon();
}
void Hero::addHero(int y, int x, Board game_board)
{ 																								// add e remove
	game_board.addAt(y, x, 'P');
}

void Hero::removeHero(Board game_board)
{
    game_board.addAt(gety(), getx(), ' ');
}