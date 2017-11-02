#ifndef __CMD_H__
#define __CMD_H__

#include <iostream>

class CMD : public Base
{
	private:
		vector<string>* statement;
	public:
	
	CMD() : Base() {};
	CMD(vector<string>& prompt) : Base() 
	{
		statement = &prompt;
		this->setFailed(true);
	};
	

	void execute() //MAKE SURE TO SET didFail bool when execvp runs 
	{
		for(int i = 0; i < statement->size(); i++)
		{
			cout << statement->at(i) << endl;
		}
	}
	
	bool setfailed(bool b)
	{
		Base::failed = b;
	}
	bool getFail()
	{
		return Base::getFail();
	}
};

#endif
