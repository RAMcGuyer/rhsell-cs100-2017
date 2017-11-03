#ifndef __CMDS_H__
#define __CMDS_H__

class CMDS : public Base
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

#endif

