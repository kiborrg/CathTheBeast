class Trap
{
protected:
	int X; //Клетка по горизонтали
	int Y; //Клетка по вертикали
public:

	Trap()
	{
		X = 0;
		Y = 0;
	}

	Trap(int new_X, int new_Y)
	{
		this->X = new_X;
		this->Y = new_Y;
	}

	int GetX()
	{
		return this->X;
	}

	int GetY()
	{
		return this->Y;
	}

	void Set(int new_X, int new_Y)
	{
		this->X = new_X;
		this->Y = new_Y;
	}

	~Trap() {};
};

class Hunter : public Trap
{
private:

public:
	Hunter() : Trap() {}
	Hunter(int new_X, int new_Y) : Trap(new_X, new_Y) {}

	void Move(int new_X, int new_Y)
	{
		this->X = new_X;
		this->Y = new_Y;
	}

	~Hunter() {};
};



class Beast : public Hunter
{
private:
	bool KnowsTrapLocation;
public:
	Beast() : Hunter() 
	{
		this->KnowsTrapLocation = false;
	}

	Beast(int new_X, int new_Y, bool KnowsTrapLocation) : Hunter(new_X, new_Y) 
	{
		this->KnowsTrapLocation = KnowsTrapLocation;
	}

	bool KnowsTrap()
	{
		return this->KnowsTrapLocation;
	}

	~Beast() {};
};