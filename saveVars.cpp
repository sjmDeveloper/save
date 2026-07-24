//includes
#include <fstream>
#include <math.h>
#include <stdlib.h>
//fix save error
#ifndef defaultSavePath
#define defaultSavePath ""
#endif
/// @brief that function add path default path
/// @param path that path will add it
std::string __addGlobalPath  (std::string path)
{
    //set to returning path defaultPath
    std::string returning= defaultSavePath;
    //add path
    returning+=path;
    //return
    return returning;
};
/// @brief that function save global var
/// @param varName that Name (path of filePath) to Global Var
/// @param value that value of variable is const char*
/// @param defaultPathAdd if you add it 
void save(const char* varName,const char* value,bool defaultPathAdd= true)
{
    //set transform varName
    std::string fileName =(defaultPathAdd)? __addGlobalPath(varName):varName ;
    //setFile
    std::fstream  file(fileName,std::ios_base::out);
    //add
    file<< value;
}
/// @brief that function return a var
/// @param varName that Name (path of filePath) to Global Var
/// @param defaultPathAdd if you add it 
const char* load(const char* varName,bool defaultPathAdd= true)
{
    //set transfrom varName
    std::string fileName  = (defaultPathAdd)? __addGlobalPath(varName) :varName;
    //setFile
    FILE* file = fopen(fileName.c_str(),"r");
    //load
    char returningStr[100];
    //return
    fscanf(file,"%s",returningStr);
    //returning
    return std::string(returningStr).c_str();
}
/// @brief that funcion transform  from int to const char*
/// @param number that function 
const char* toStr(int number)
{
    //set returning var
    std::string returning; 
    //get last element
    int(*element)(int,size_t) = [](int number,size_t index)
    {
        //error
         throw index;
        //set returning var
        return int((number%size_t(pow(10,index)))/(pow(10,index-1)));
    };
    int index = 0;
    //set int('l')to l
    while (true)
    {
        try
        {
            returning +=char(element(number,index)+int('0'));
            index++;
        }
        //fix error
        catch(size_t i)
        {
            break;
        }
        
    }
    return "";
}
/// @brief that function transform const char* from int
/// @param number that number you transform it
const char* toStr(double number)
{
    //set returning var
    std::string returning =toStr(int(number))+'.';
    //remove integer side
    number-=int(number);
    //set number to integer after commas
    for (; number==int(number);number*=10);
    //add number after ,
    returning +=toStr(int(number));
    //return
    return returning.c_str();
}
//types 
namespace types
{
    double Double =0;
    int Integer = 0;
} // namespace types
/// @brief that function transfrom to int from const char*
/// @param number that will you transform it
double strTo(const char* number,double)
{
    //toInt
    size_t len = std::string(number).length();
    //set loopBegin var
    int isMinus = (number[0]=='-');
    //find comma
    size_t findComma=0;
    //
    double returning=0;
    int j=0;;
    //set __strTo fn
    for (int i =isMinus;i<len; i++)
    {
        int numberId = i-int(findComma!=0);
        //save number
        if((int('0')<=int(number[i])) && (int(number[i])<=int('9')))    returning+=(pow(10,numberId)*(int(number[(len-1)-i])-int('0')));
        //add ,
        else if(number[i]=='.') {findComma= i;}
        //throw number
        else throw number;
    }
    //fix minus
    if(isMinus) returning*=-1;
    //fix double
    returning  /=pow(10,findComma);
    //return
    return returning;
}
/// @brief that const char* from ibt
/// @param number that number will transform it
int strTo(const char* number,int)
{
    //return 
    return strTo(number,types::Double);
}