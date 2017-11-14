#ifndef __CMD_H__
#define __CMD_H__
#include "Base.h"
#include <sys/stat.h>


class Test : public Base
{
private:
  bool err;
  vector<string> test;
  
  //Returns 0, 1 or 2 depending on flag type. 0 is default or -e
  unsigned checkFlag()
  {
    unsigned flagVal
    if(text.at(0) == "-d")
    {
      flagVal = 1;
    }
    else if(text.at(0) == "-f")
    {
      flagVal = 2;
    }
    else
    {
      flagVal = 0;
    }
    
    return flagVal;  
  }
public:

  // CONSTRUCTOR //
  Test(String s): Base()
  {
    err = false;
    setTest(s);
  }
  
  ~Test(){};
  
  // PUBLIC FUNCTIONS //
  void setTest(string s)
  {
    if(s.front() == "[")
    {
      if(s.back() == "]")
      {
        s = s.substr(1, s.size()-3);
      }
      else
      {
        err = true;
      }
    }
    else
    {
      s = s.substr(4);
    }
    
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");
    tokenizer tokens(s, sep);
		
	  //iterating through your tokenizer and putting it into a vector
	  for (tokenizer::iterator tok_iter = tokens.begin();
	  	 tok_iter != tokens.end(); ++tok_iter)
	  {
	  	this->test.push_back(*tok_iter);
	  }    
  } //end setTest
  
  void execute()
  {
    unsigned flagCode;
    struct stat buf;
    bool result;
    flagCode = checkFlag();
    
    if(err)
    {
      result = false;
    }
    else
    {
      
      if(stat(test.at(test.size()-1), &buf) != 0);
      {
        if(flagCode == 0)
        {
          result = true;
        }
        else if(flagCode == 1)
        {
          if(S_ISDIR(buf.st_mode) == 0)
          {
            result = true;
          }
          else
          {
            result = false;
          }
        }
        else if(flagCode == 2)
        {
          if(S_ISREG(buf.st_mode) == 0)
          {
            result = true;
          }
          else
          {
            result = false;
          }
        }
      }
    }
    
    this->setDidRun(true);
    if(result)
    {
      cout << "(True)" << endl;
    }
    else
    {
      Base::setFail(true);
      cout << "(False)" << endl;
    } 
  } //end execute()
  
  bool getFail()
  {
      return Base::getFail();
  }
  
  bool getDidRun()
  {
      return Base::getDidRun();
  }

  void setDidRun(bool didRun)
  {
      return Base::setDidRun(didRun);
  }
  
};
#endif