#ifndef __TEST_H__
#define __TEST_H__
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
    unsigned flagVal;
    if(test.at(0) == "-d")
    {
      flagVal = 1;
    }
    else if(test.at(0) == "-f")
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
  Test(string s): Base()
  {
    err = false;
    setTest(s);
  }
  
  // DECONSTRUCTOR //
  ~Test(){};
  
  // PUBLIC FUNCTIONS //
  void setTest(string s)
  {
    //test, delete later
    cout << "s before substr(): " << s << endl;
    if(s.at(0) == '[')
    {
      if(s.at(s.size()-1) == ']')
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
    
    //test, delete later
    cout << "s after substr(): " << s << endl;
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(" ");
    tokenizer tokens(s, sep);
		
	  //iterating through your tokenizer and putting it into a vector
	  for (tokenizer::iterator tok_iter = tokens.begin();
	  	 tok_iter != tokens.end(); ++tok_iter)
	  {
	  	this->test.push_back(*tok_iter);
	  } 
    
    //test, delete later
    cout << "Contents of test: " << endl;
    for(unsigned j = 0; j < test.size(); j++)
    {
      cout << "Index: " << j << " -- " << test.at(j) << endl;
    }   
  } //end setTest
  
  void execute()
  {
    unsigned flagCode;
    struct stat buf;
    bool result = false;
    flagCode = checkFlag();
    
  test.at(test.size()-1).erase(test.at(test.size()-1).find_last_not_of(" \n\t\r")+1);
    if(!err)
    {
      char* c[1];
      c[0] = (char*) test.at(test.size()-1).c_str();
      /*
          Takes last spot in test vector, (the index containing the file path)
        and passes that string into stat(). If is a valid path, the bool result will
        be set to true, unless the user specifies a flag, in which case that will
        also be checked. The result will be true if the file found matches the flag. 
      */
      if(stat(c[0], &buf) != 0);
      {
        if(flagCode == 0)
        {
          result = true;
        }
        else if(flagCode == 1)
        {
          if(S_ISDIR(buf.st_mode) != 0)
          {
            result = true;
          }
        }
        else if(flagCode == 2)
        {
          if(S_ISREG(buf.st_mode) != 0)
          {
            result = true;
          }
        }
      }
    } //end flag checking file validation
    
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