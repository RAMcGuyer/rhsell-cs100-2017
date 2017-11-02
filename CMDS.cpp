#include "CMDS.h"

class CMDS : public Base()
{
	private:
		vector<CMD> commands;
		
	public:
		CMDS(queue &q) : Base()
		{
			fillCommands(q)
		}
		
	void fillCommands(queue &q)
	{
		while(!(q->empty()))
		{
			vector<string> args;
		}
		
	}
};
