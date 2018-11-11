/*  pascal_gram_checker
    oop homework3
    题目：pascal源程序语法检查器
    说明：pascal语言中，复合语句用begin…end表示，条件语句用if…then…else…表示，
    其中，else子句可以出现也可以不出现。
    编写一个程序，检查pascal源文件中的begin和end是否配对，if、then、else是否配对。

要求：
（1）	要求将主要代码定义为一个类，类名称自定；
（2）	要求将该类定义在独立命名空间grammcheck中；
（3）	语法检查部分要求使用堆栈技术，可自定义堆栈类或采用标准库的堆栈类；
（4）	要求编写main函数，调用该检查函数，对给定的pascal源文件进行检查，并输出检查结果；
（5）	要求有异常处理逻辑（主要是打开文件部分）；
（6）	提交的文件中，须包含配套的被检查pascal源文件；
*/
#include<iostream>
#include<stdlib.h>  
#include<vector>
#include<stack>
#include<fstream>

using namespace std;

namespace grammcheck{
class PascalChecker{
public:
    stack<string> key_stack;
    vector<string> words;
    vector<string> codes;
    PascalChecker(const string &filename);
    //输出读入代码
    void OutPutCode(ostream& os){
        for (auto line:codes){
            os<<line<<endl;
        }
    }
    //输出提取的关键词
    void OutPutWords(ostream& os){
        os<<"the key words are:"<<endl;
        for (auto word:words){
            os<<word<<endl;
        }
    }
    //执行语法配对检查
    void check();
private:
    //将字符串按照指定字符分离
    vector<string> split(const string &s, const string &seperator);
    //判断是否为关键词
    bool isKeyWord(const string &key);
    //将整个代码分离出关键词
    void splitWords();
};
PascalChecker::PascalChecker(const string &filename){
        ifstream is(filename);
        string s;
        //异常处理 当文件不存在时输出报错信息
        if (!is)
            cout<<"CAN NOT FIND: "<<filename<<endl;
        while(getline(is,s)){
            codes.push_back(s);
        }
        splitWords();
        
    }

vector<string>  PascalChecker::split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;
    while(i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for(string_size x = 0; x < seperator.size(); ++x)
                if(s[i] == seperator[x]){
                    ++i;
                    flag = 0;
                    break;
                    }
        }
        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for(string_size x = 0; x < seperator.size(); ++x)
                if(s[j] == seperator[x]){
                    flag = 1;
                    break;
                    }
            if(flag == 0)
                ++j;
        }
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
    }

bool PascalChecker::isKeyWord(const string &key){
    if(key=="begin"||key=="end"||key=="if"||key=="then"||key=="else") return true;
    else return false;
    }

void PascalChecker::splitWords(){
    string seperator(" ;");//分离的符号为 空格和冒号
    vector<string> line_words;
    for (auto line:codes){
        line_words=split(line,seperator);
        for(auto word:line_words){
            if(isKeyWord(word))
                words.push_back(word);
        }
    }
    }

void PascalChecker::check(){
    cout<<endl;
    string pres_key;
    for (auto word:words){
        //对提取出的关键词按照顺序进行遍历
        //如果是一个开放关键词，将其推入到栈中
        if (word=="if"){
            key_stack.push(word);
        }
        else if(word=="begin"){
            //由于begin end 不能出现在if then中间，为避免这种情况发生，这里做一个特殊处理，前面非空且为if时报错。
            if(!key_stack.empty()){
                if(key_stack.top()=="if"){
                    cout<<"\"begin end\" can not in \"if then\""<<endl;
                    break;
                }
            }
            key_stack.push(word);
        }
        //如果是一个封闭关键词，则当栈空时报错，否则将栈元素弹出。如果弹出的不是对应的开放关键词，则报错。
        else if (word=="end")
        {
            if(key_stack.empty()){
                cout<<"begin end not match"<<endl;
                break;
            }else{
                pres_key=key_stack.top();
                key_stack.pop();
                if(pres_key!="begin"){
                    cout<<"begin end not match"<<endl;
                    break;
                }
            }
        }
        else if(word=="else"){
            if(key_stack.empty()){
                cout<<"\"then else\" not match"<<endl;
                break;
            }else{
                pres_key=key_stack.top();
                key_stack.pop();
                if(pres_key!="then"){
                    cout<<"\"then else\" not match"<<endl;
                    break;
                }
            }
        }
        else if(word=="then"){
            if(key_stack.empty()){
                cout<<"\"if then\" not match"<<endl;
                break;
            }else{
                pres_key=key_stack.top();
                key_stack.pop();
                if(pres_key!="if"){
                    cout<<"\"if then\" not match"<<endl;
                    break;
                }
                //这里又向栈里添加关键词是用于else的检测
                key_stack.push(word);
            }
        }
    }
    if(key_stack.empty()){
        //如果堆栈为空，则说明全部匹配正确，正常退出
        cout<<"match success!"<<endl;
    }else{
        //如果堆栈不为空，则需要检测是否只剩下then关键词，如果不是，则说明有配对不成功的情况发生。(因为允许有if then出现的情况)
        while(!key_stack.empty()){
            if(key_stack.top()!="then"){
                cout<<"not match at "<<key_stack.top()<<endl;
                break;
            }
            key_stack.pop();
        }
    }
}
};

using namespace grammcheck;
int main(void){
    PascalChecker checker("pascal.txt");
    checker.OutPutWords(cout);
    checker.check();
    system("pause");
    return 0;
}